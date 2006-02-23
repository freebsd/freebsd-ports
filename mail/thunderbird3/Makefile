# New ports collection makefile for:	mozilla-thunderbird
# Date created:			4 September 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/mail/thunderbird-devel/Makefile,v 1.16 2005/11/27 18:53:59 marcus Exp $
#

PORTNAME=	thunderbird
DISTVERSION=	1.5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	thunderbird/releases/${DISTVERSION}/source
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

WANT_GNOME=	yes
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GCC=	3.4+
CFLAGS+=	-I${X11BASE}/include

MOZ_EXTENSIONS=	wallet,spellcheck,xmlextras,webservices
MOZ_PROTOCOLS=	http,file,jar,viewsource,res,data
MOZ_GRAPHICS=	default,-xbm
MOZ_OPTIONS=	--enable-single-profile --disable-profilesharing	\
		--enable-application=mail -enable-official-branding
MOZ_MK_OPTIONS=	MOZ_MOZ_THUNDERBIRD=1
MOZ_EXPORT=	MOZ_THUNDERBIRD=1

PORTNAME_ICON=	${PREFIX}/lib/${PORTNAME}/icons/default.xpm

SYSTEM_PREFS=	${FAKEDIR}/lib/${PORTNAME}-${PORTVERSION}/defaults/pref/${PORTNAME}.js
MOZ_PIS_SCRIPTS=moz_pis_S50cleanhome

OPTIONS=

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/Makefile.common"

.if ( ${ARCH} == "alpha" && ${OSVERSION} < 500035 ) || ${ARCH} == "sparc64"
IGNORE=	core dumps at runtime
.endif # ( ${ARCH} == "alpha" && ${OSVERSION} < 500035 ) || ${ARCH} == "sparc64"

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config_make-jars.pl
.endif # ${PERL_LEVEL} < 500600

post-extract::
	@${SED} -e 's|@PORTNAME_ICON@|${PORTNAME_ICON}|' \
		<${FILESDIR}/${PORTNAME}.desktop.in >${WRKDIR}/${PORTNAME}.desktop

post-patch:
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

pre-install:
	${MKDIR} ${FAKEDIR}/lib/${PORTNAME}/defaults
	${CP} -RL ${WRKSRC}/dist/bin/defaults/isp \
		${FAKEDIR}/lib/${PORTNAME}/defaults
	@cd ${FAKEDIR}/lib/${PORTNAME}/defaults/isp && \
		${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|lib/${PORTNAME}/defaults/isp/|' >> ${PLIST} && \
		${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm lib/${PORTNAME}/defaults/isp/|' \
		>> ${PLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/lib/${PORTNAME}/defaults/isp 2>/dev/null || ${TRUE}" >> ${PLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/lib/${PORTNAME}/defaults 2>/dev/null || ${TRUE}" >> ${PLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/lib/${PORTNAME}/ 2>/dev/null || ${TRUE}" >> ${PLIST}
	@${ECHO_CMD} 'share/applications/${PORTNAME}.desktop' >> ${PLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/other-licenses/branding/${PORTNAME}/default.xpm \
		${PREFIX}/lib/${PORTNAME}/chrome/icons/default/default.xpm

.include <bsd.port.post.mk>
