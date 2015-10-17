# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	firefox
DISTVERSION=	41.0.2
DISTVERSIONSUFFIX=.source
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/source \
		MOZILLA/${PORTNAME}/candidates/${DISTVERSION}-candidates/build1/source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

BUILD_DEPENDS=	nspr>=4.10.8:${PORTSDIR}/devel/nspr \
		nss>=3.19.2:${PORTSDIR}/security/nss \
		libevent2>=2.0.21_2:${PORTSDIR}/devel/libevent2 \
		soundtouch>=1.8.0:${PORTSDIR}/audio/soundtouch \
		harfbuzz>=0.9.34:${PORTSDIR}/print/harfbuzz \
		graphite2>=1.2.4:${PORTSDIR}/graphics/graphite2 \
		libvorbis>=1.3.5:${PORTSDIR}/audio/libvorbis \
		libvpx>=1.3.0:${PORTSDIR}/multimedia/libvpx \
		sqlite3>=3.8.9:${PORTSDIR}/databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		v4l_compat>0:${PORTSDIR}/multimedia/v4l_compat \
		autoconf-2.13:${PORTSDIR}/devel/autoconf213 \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip
#		opus>=1.1:${PORTSDIR}/audio/opus \

LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l

USE_GECKO=	gecko
CONFLICTS_INSTALL=	firefox-esr-31.* firefox-esr-24.* firefox-esr-17.*
MOZ_PKGCONFIG_FILES=	# empty
USE_MOZILLA=	-opus
MOZILLA_NAME=	Firefox

USE_QT5=	# empty
QT_NONSTANDARD=	yes
USE_GL=		gl
USES=		dos2unix tar:xz
DOS2UNIX_FILES=	media/webrtc/trunk/webrtc/system_wrappers/source/spreadsortlib/spreadsort.hpp

FIREFOX_ICON=		${MOZILLA}.png
FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default48.png
MOZ_OPTIONS=	--program-transform-name='s/firefox/${MOZILLA}/' \
		--enable-application=browser \
		--enable-official-branding

OPTIONS_EXCLUDE=	LOGGING
OPTIONS_DEFAULT=	GTK2

OPTIONS_SINGLE+=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	GTK2 GTK3

.include "${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.pre.mk>

WRKSRC:=	${WRKDIR}/mozilla-release

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
	@${REINPLACE_CMD} -e '/MOZPNG/s/=[0-9]*/=10511/' \
		${WRKSRC}/configure.in
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
