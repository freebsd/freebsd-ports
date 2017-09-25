# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thunderbird
DISTVERSION=	52.3.0
PORTREVISION=	2
CATEGORIES=	mail news net-im ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/source \
		MOZILLA/${PORTNAME}/candidates/${DISTVERSION}-candidates/build1/source
DISTFILES=	${PORTNAME}-${DISTVERSION}.source${EXTRACT_SUFX}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}.source${EXTRACT_SUFX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

BUILD_DEPENDS=	nspr>=4.13.1:devel/nspr \
		nss>=3.28.3:security/nss \
		libevent>=2.0.21_2:devel/libevent \
		harfbuzz>=1.4.1:print/harfbuzz \
		graphite2>=1.3.8:graphics/graphite2 \
		png>=1.6.25:graphics/png \
		libvorbis>=1.3.5,3:audio/libvorbis \
		libvpx>=1.5.0:multimedia/libvpx \
		sqlite3>=3.17.0:databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf-2.13:devel/autoconf213 \
		yasm:devel/yasm \
		zip:archivers/zip
#		soundtouch>=1.9.0:audio/soundtouch \

LIB_DEPENDS=	libv4l2.so:multimedia/libv4l

SSP_UNSAFE=	yes
USE_GECKO=	gecko
USE_MOZILLA=	-soundtouch

USE_GL=		gl
USES=		tar:xz

MOZ_OPTIONS=	--enable-application=mail --enable-official-branding
MOZ_MK_OPTIONS=	MOZ_THUNDERBIRD=1 MAIL_PKG_SHARED=1
MOZ_EXPORT=		MOZ_THUNDERBIRD=1 MAIL_PKG_SHARED=1
MOZ_PKGCONFIG_FILES=

PORTNAME_ICON=	${MOZILLA}.png
PORTNAME_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default48.png

SYSTEM_PREFS=	${FAKEDIR}/lib/${PORTNAME}/defaults/pref/${PORTNAME}.js
MOZ_PIS_SCRIPTS=moz_pis_S50cleanhome

OPTIONS_DEFINE=	LIGHTNING RUST
OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	GTK2 GTK3
OPTIONS_DEFAULT=BUNDLED_CAIRO CANBERRA GTK3 LIGHTNING

.include "${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.pre.mk>

WRKSRC:=	${WRKDIR}/${PORTNAME}-${DISTVERSION}
MOZSRC:=	${WRKSRC}/mozilla

.if ${PORT_OPTIONS:MLIGHTNING}
MOZ_OPTIONS+=	--enable-calendar
.else
MOZ_OPTIONS+=	--disable-calendar
.endif

post-extract:
	@${SED} -e 's|@PORTNAME_ICON@|${PORTNAME_ICON}|;s|@MOZILLA@|${MOZILLA}|' \
		<${FILESDIR}/thunderbird.desktop.in >${WRKDIR}/${MOZILLA_EXEC_NAME}.desktop

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/mail/app/nsMailApp.cpp

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf-2.13)
	(cd ${MOZSRC} && ${LOCALBASE}/bin/autoconf-2.13)
	(cd ${MOZSRC}/js/src/ && ${LOCALBASE}/bin/autoconf-2.13)

port-pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/defaults

post-install:
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA_EXEC_NAME}.desktop ${STAGEDIR}${PREFIX}/share/applications
	${LN} -sf ${PORTNAME_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME_ICON}

.include <bsd.port.post.mk>
