# New ports collection makefile for:	mozilla-thunderbird
# Date created:			4 September 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/mail/thunderbird/Makefile,v 1.18 2009/01/02 21:16:20 mezz Exp $
#

PORTNAME=	thunderbird
DISTVERSION=	2.0.0.24
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	thunderbird/releases/${DISTVERSION}/source
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

DEPRECATED=	Upstream support dropped. Please consider using mail/thunderbird3 instead
CONFLICTS=	lightning-0.[0-9]* thunderbird-3*
WANT_GNOME=	yes
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GECKO=	gecko
WANT_PERL=	yes

MOZ_EXTENSIONS=	wallet,spellcheck,xmlextras,webservices,auth,transformiix
MOZ_PROTOCOLS=	http,ftp,file,jar,viewsource,res,data
MOZ_GRAPHICS=	default,-xbm
MOZ_OPTIONS=	--with-default-mozilla-five-home=${PREFIX}/lib/${MOZILLA} \
		--enable-single-profile --disable-profilesharing \
		--enable-application=mail --enable-official-branding
MOZ_MK_OPTIONS=	MOZ_MOZ_THUNDERBIRD=1
MOZ_EXPORT=	MOZ_THUNDERBIRD=1

PORTNAME_ICON=	${PREFIX}/lib/${PORTNAME}/icons/default.xpm

SYSTEM_PREFS=	${FAKEDIR}/lib/${PORTNAME}-${PORTVERSION}/defaults/pref/${PORTNAME}.js
MOZ_PIS_SCRIPTS=moz_pis_S50cleanhome

OPTIONS=

.include <bsd.port.pre.mk>

GECKO_PTHREAD_LIBS!=${CC} -dumpspecs | ${GREP} -m 1 '%{\!pg: %{pthread:' | ${SED
} -e 's|^.*%{\!pg: %{pthread:|| ; s|}.*$$||' || ${TRUE}

.if (${ARCH}=="sparc64" && ${OSVERSION} < 601101)
IGNORE=	core dumps on ${ARCH}, kern.osreldate>=601101 needed
.endif

post-extract::
	@${SED} -e 's|@PORTNAME_ICON@|${PORTNAME_ICON}|' \
		<${FILESDIR}/${PORTNAME}.desktop.in >${WRKDIR}/${PORTNAME}.desktop

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/security/manager/ssl/src/Makefile.in
	@${REINPLACE_CMD} -e 's|--without-nss||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:C/-pthread/${GECKO_PTHREAD_LIBS}/}|' \
		${WRKSRC}/storage/build/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/local/netscape|${LOCALBASE}|g' \
		-e 's|/usr/local/lib/netscape|${LOCALBASE}/lib|g' \
		${WRKSRC}/xpcom/*/SpecialSystemDirectory.cpp
	@${FIND} ${WRKSRC} -name all.js | ${XARGS} ${REINPLACE_CMD} -e \
		'/accessibility.typeaheadfind.enablesound/s/true/false/ ; \
		/dom.disable_window_open_feature.toolbar/s/false/true/'
	@${REINPLACE_CMD} -e 's|<iconv.h>|\"${LOCALBASE}/include/iconv.h\"|g' \
		${WRKSRC}/configure \
		${WRKSRC}/intl/uconv/native/nsNativeUConvService.cpp \
		${WRKSRC}/xpcom/io/nsNativeCharsetUtils.cpp

port-pre-install:
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
	${FAKEDIR}/bin/thunderbird-config ${FAKEDIR}/bin/thunderbird
	${RM} -f ${FAKEDIR}/bin/*.bak
	${MKDIR} ${FAKEDIR}/lib/${PORTNAME}/defaults
	${CP} -RL ${WRKSRC}/dist/bin/isp \
		${FAKEDIR}/lib/${PORTNAME}

pre-install:
	@${ECHO_CMD} 'share/applications/${PORTNAME}.desktop' >> ${PLIST}
	@${ECHO_CMD} '@dirrmtry share/applications' >> ${PLIST}

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/other-licenses/branding/${PORTNAME}/default.xpm \
		${PORTNAME_ICON}

.include <bsd.port.post.mk>
