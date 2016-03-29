# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	firefox
DISTVERSION=	45.0.1
DISTVERSIONSUFFIX=.source
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/source \
		MOZILLA/${PORTNAME}/candidates/${DISTVERSION}-candidates/build2/source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

BUILD_DEPENDS=	nspr>=4.12:${PORTSDIR}/devel/nspr \
		nss>=3.21.1:${PORTSDIR}/security/nss \
		libevent2>=2.0.21_2:${PORTSDIR}/devel/libevent2 \
		soundtouch>=1.9.0:${PORTSDIR}/audio/soundtouch \
		harfbuzz>=1.1.0:${PORTSDIR}/print/harfbuzz \
		graphite2>=1.3.6:${PORTSDIR}/graphics/graphite2 \
		png>=1.6.19:${PORTSDIR}/graphics/png \
		libvorbis>=1.3.5,3:${PORTSDIR}/audio/libvorbis \
		libvpx>=1.5.0:${PORTSDIR}/multimedia/libvpx \
		sqlite3>=3.9.1:${PORTSDIR}/databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		v4l_compat>0:${PORTSDIR}/multimedia/v4l_compat \
		autoconf-2.13:${PORTSDIR}/devel/autoconf213 \
		yasm:${PORTSDIR}/devel/yasm \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip

LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l

USE_GECKO=	gecko
CONFLICTS_INSTALL=	firefox-esr-45.* firefox-esr-3[18].* firefox-esr-24.*
MOZ_PKGCONFIG_FILES=	# empty
USE_MOZILLA=	# empty
MOZILLA_NAME=	Firefox

USE_QT5=	# empty
QT_NONSTANDARD=	yes
USE_GL=		gl
USES=		tar:xz

FIREFOX_ICON=		${MOZILLA}.png
FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default48.png
MOZ_OPTIONS=	--program-transform-name='s/firefox/${MOZILLA}/' \
		--enable-application=browser \
		--enable-official-branding

OPTIONS_EXCLUDE=	GSTREAMER LOGGING
OPTIONS_DEFAULT=	GTK2

OPTIONS_SINGLE+=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	GTK2 GTK3

.include "${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.pre.mk>

WRKSRC:=	${WRKDIR}/${PORTNAME}-${DISTVERSION}

.if ${PORT_OPTIONS:MALSA}
RUN_DEPENDS+=	alsa-lib>=1.0.27.2_1:${PORTSDIR}/audio/alsa-lib
.endif

.if ! ${PORT_OPTIONS:MBUNDLED_CAIRO}
BUILD_DEPENDS+=	cairo>=1.12.16_1,2:${PORTSDIR}/graphics/cairo
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
RUN_DEPENDS+=	gstreamer1-libav>=1.2.4_1:${PORTSDIR}/multimedia/gstreamer1-libav
.endif

.if ${PORT_OPTIONS:MGTK3}
BUILD_DEPENDS+=	gtk3>=3.14.6:${PORTSDIR}/x11-toolkits/gtk30
.endif

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

.include <bsd.port.post.mk>
