#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#    $MCom: ports/www/mozilla/bsd.gecko.mk,v 1.30 2006/12/09 15:32:06 ahze Exp $
#
# 4 column tabs prevent hair loss and tooth decay!

# bsd.gecko.mk abstracts the selection of gecko-based backends. It allows users
# and porters to support any available gecko backend without needing to build
# many conditional tests. ${USE_GECKO} is the list of backends that your port
# can handle, and ${GECKO} is set by bsd.gecko.mk to be the chosen backend.
# Users set ${WITH_GECKO} to the list of gecko backends they want on their system.

.if defined(USE_GECKO)
#.if defined(_POSTMKINCLUDED) && !defined(Gecko_Pre_Include)

# Please make sure all changes to this file are passed through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Gecko_Include_MAINTAINER=		gnome@FreeBSD.org
Gecko_Pre_Include=			bsd.gecko.mk


# Users should use the following syntax:
#
# WITH_GECKO= mozilla firefox seamonkey
#  Use mozilla whenever a port supports it, falling back on firefox and
#  then seamonkey.
# WITH_GECKO= firefox
#  Sets your preferred backend. With this example, firefox will always
#  be chosen, unless the port doesn't support a firefox backend. In that
#  case, you get whatever the porter chose as the default. Better to use
#  the first example.
#
#
# Ports should use the following:
#
# USE_GECKO= mozilla firefox seamonkey
#  The list of gecko backends that the port supports. Unless the user
#  overrides it with WITH_GECKO, the first gecko listed in USE_GECKO
#  will be the default. In the above example, www/mozilla will be used
#  as a gecko backend unless WITH_GECKO=firefox or WITH_GECKO=seamonkey
#  is defined by the user.
#
# USE_GECKO= firefox-devel<->firefox
#  This will sed -e 's/firefox/firefox-devel/' on Makefile.in's and configure 
#  if ${GECKO}=="firefox-devel"
#
#  Example:
#  USE_GECKO= mozilla firefox seamonkey
#  .include <bsd.port.pre.mk>
#  .include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
#  post-patch:
#	@${REINPALCE_CMD} -e 's|mozilla-|${GECKO}-|' \
#		${WRKSRC}/configure
#
#  If you want your port to check the ${GECKO} variable to see which backend
#  has been chosen.
#
#  Example:
#  USE_GECKO= mozilla firefox seamonkey
#  .include <bsd.port.pre.mk>
#  .include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
#  post-patch:
#  .if ${GECKO}=="seamonkey"
#	@${REINPLACE_CMD} -e 's|mozilla-|seamonkey-|' \
#		${WRKSRC}/configure
#  .endif

.if ${OSVERSION} >= 500000
.if (${ARCH}!="sparc64" || ${OSVERSION} >= 601101) && ${ARCH}!="ia64"
_GECKO_ALL=	firefox nvu seamonkey thunderbird xulrunner flock firefox15
.endif
.endif
_GECKO_ALL+=	mozilla

thunderbird_PORTSDIR=	mail

.for gecko in ${_GECKO_ALL}
${gecko}_PORTSDIR?=	www
${gecko}_DEPENDS?=	${PORTSDIR}/${${gecko}_PORTSDIR}/${gecko}
${gecko}_PLIST?=	${LOCALBASE}/lib/${gecko}/libgtkembedmoz.so
.endfor

# Figure out which mozilla to use
# Weed out bad options in USE_GECKO
.for badgecko in ${USE_GECKO}
. if ${_GECKO_ALL:M${badgecko:C/^([^<->]+).*/\1/}}!=""
GOOD_USE_GECKO+=	${badgecko:C/^([^<->]+).*/\1/}
. endif
. if ${_GECKO_ALL:M${badgecko:C/^[^<->]+<->([^<->]+).*/\1/}}!="${badgecko:C/^([^<->]+).*/\1/}"
${badgecko:C/^([^<->]+).*/\1/}_HACK=	s:${badgecko:C/^[^<->]+<->([^<->]+).*/\1/}:${badgecko:C/^([^<->]+).*/\1/}:g
. endif
.endfor

.undef GECKO_FALLTHROUGH
.undef _FOUND_WITH_GECKO
# Figure out which gecko to use and weed out the bad ones
.if defined(WITH_GECKO) && defined(GOOD_USE_GECKO)
. for badgecko in ${WITH_GECKO}
.  if ${GOOD_USE_GECKO:M${badgecko}}!=""
GOOD_WITH_GECKO+=	${badgecko}
.  endif
. endfor
. if defined(GOOD_WITH_GECKO)
.  for gecko in ${GOOD_WITH_GECKO}
.   if !defined(GECKO_FALLTHROUGH)
GECKO=	${gecko}
GECKO_FALLTHROUGH=	${TRUE}
_FOUND_WITH_GECKO=	${TRUE}
.   endif
.  endfor
. endif
.endif

.if !defined(GECKO) && defined(GOOD_USE_GECKO)
. for gecko in ${GOOD_USE_GECKO}
.  if !defined(GECKO_FALLTRHOUGH)
GECKO=	${gecko}
GECKO_FALLTRHOUGH=	${TRUE}
.  endif
. endfor
.endif

# Generic defines
BROWSER_LINUX_PLUGINS_DIR?=	${LOCALBASE}/lib/browser_linux_plugins
BROWSER_PLUGINS_DIR?=		${LOCALBASE}/lib/browser_plugins

GECKO_CONFIG?=			${LOCALBASE}/bin/${GECKO}-config
XPIDL?=				${LOCALBASE}/lib/${GECKO}/xpidl
XPIDL_INCL?=			`${GECKO_CONFIG} --idlflags`

.if defined(GECKO) && ${_GECKO_ALL:M${GECKO}}!=""
BUILD_DEPENDS+=	${${GECKO}_PLIST}:${${GECKO}_DEPENDS}
RUN_DEPENDS+=	${${GECKO}_PLIST}:${${GECKO}_DEPENDS}
.else
IGNORE=	Unable to find a supported gecko, please check USE_GECKO
.endif

pre-everything:: _gecko-pre-everything

_gecko-pre-everything::
	@${ECHO_CMD} ""
.if !defined(_FOUND_WITH_GECKO) && defined(WITH_GECKO)
	@${ECHO_CMD} " Warning: ${PORTNAME} does not support any gecko you"
	@${ECHO_CMD} " listed in WITH_GECKO=${WITH_GECKO}."
	@${ECHO_CMD} " \"${GECKO}\" will be used"
	@${ECHO_CMD} ""
	@${ECHO_CMD} " for gecko support, but you can change that by using one of"
	@${ECHO_CMD} " the following values:"
.else
	@${ECHO_CMD} " ${PORTNAME} is using ${GECKO} for gecko support, but you can"
	@${ECHO_CMD} " change that by defining WITH_GECKO to the following values:"
.endif
	@${ECHO_CMD} ""
.for gecko in ${GOOD_USE_GECKO}
	@${ECHO_CMD} "   ${gecko} "
.endfor
	@${ECHO_CMD} ""

post-patch: gecko-post-patch

gecko-post-patch:
.if defined(${GECKO}_HACK)
	${FIND} ${WRKSRC} -name "Makefile.in" -type f -o -name "configure" -type f | \
		${XARGS} ${REINPLACE_CMD} -e ${${GECKO}_HACK}
.endif

#.endif # end it all
.endif
# HERE THERE BE TACOS
