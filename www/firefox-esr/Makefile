# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	firefox
DISTVERSION=	52.3.0
DISTVERSIONSUFFIX=esr.source
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}esr/source \
		MOZILLA/${PORTNAME}/candidates/${DISTVERSION}esr-candidates/build2/source
PKGNAMESUFFIX=	-esr

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

BUILD_DEPENDS=	nspr>=4.13.1:devel/nspr \
		nss>=3.29.5:security/nss \
		libevent>=2.0.21_2:devel/libevent \
		harfbuzz>=1.4.1:print/harfbuzz \
		graphite2>=1.3.8:graphics/graphite2 \
		png>=1.6.28:graphics/png \
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

USE_GECKO=	gecko
CPE_PRODUCT=	${PORTNAME}_esr
CONFLICTS_INSTALL=	firefox-[0-9]*
MOZ_PKGCONFIG_FILES=	# empty
USE_MOZILLA=	-soundtouch
MOZILLA_NAME=	Firefox

USE_GL=		gl
USES=		tar:xz

FIREFOX_ICON=		${MOZILLA}.png
FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default48.png
MOZ_OPTIONS=	--enable-application=browser \
		--enable-official-branding

OPTIONS_DEFINE=		RUST
OPTIONS_DEFAULT=	BUNDLED_CAIRO GTK2

OPTIONS_SINGLE+=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	GTK2 GTK3

.include "${.CURDIR}/../../www/firefox/Makefile.options"

WRKSRC:=	${WRKDIR}/${PORTNAME}-${DISTVERSION}esr

post-extract:
	@${SED} -e 's|@FIREFOX_ICON@|${FIREFOX_ICON}|' -e 's|@MOZILLA@|${MOZILLA}|' \
		-e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|' \
		<${FILESDIR}/firefox.desktop.in >${WRKDIR}/${MOZILLA}.desktop

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf-2.13)
	(cd ${WRKSRC}/js/src/ && ${LOCALBASE}/bin/autoconf-2.13)

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${LN} -sf ${FIREFOX_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${FIREFOX_ICON}

.include <bsd.port.mk>
