# $FreeBSD$

PORTNAME=	telegram-desktop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.23
CATEGORIES=	net-im

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Telegram Desktop messaging app

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dee>0:devel/dee \
		gyp:devel/py-gyp@${PY_FLAVOR}
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libavformat.so:multimedia/ffmpeg \
		libdbus-1.so:devel/dbus \
		libminizip.so:archivers/minizip \
		libopenal.so:audio/openal-soft \
		libopus.so:audio/opus \
		libpulse.so:audio/pulseaudio

USES=		cmake:noninja,outsource desktop-file-utils gmake pkgconfig python:build ssl
USE_GITHUB=	yes
GH_ACCOUNT=	telegramdesktop
GH_PROJECT=	tdesktop
GH_TUPLE=	catchorg:Catch2:5ca44b68:catch/Telegram/ThirdParty/Catch \
		mapbox:variant:550ac2f:variant/Telegram/ThirdParty/variant \
		Microsoft:GSL:c5851a8:gsl/Telegram/ThirdParty/GSL \
		telegramdesktop:libtgvoip:757a5d8e:libtgvoip/Telegram/ThirdParty/libtgvoip
USE_GNOME=	glib20 gtk30
USE_QT5=	core gui imageformats network widgets buildtools_build qmake_build
USE_XORG=	x11 xcb

CMAKE_SOURCE_PATH=	${WRKSRC}/out/Release

GYP_DEFINES=	TDESKTOP_DISABLE_CRASH_REPORTS,TDESKTOP_DISABLE_AUTOUPDATE,TDESKTOP_DISABLE_REGISTER_CUSTOM_SCHEME

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100000
CC=		clang40
CXX=		clang++40
BUILD_DEPENDS+=	clang++40:devel/llvm40
RUN_DEPENDS+=	clang++40:devel/llvm40
.endif

post-patch:
	@cd ${WRKSRC} && \
		(${SED} -e " \
			s|%%QT_VERSION%%|${QT5_VERSION}| ; \
			s|%%LOCALBASE%%|${LOCALBASE}| ; \
			s|%%CFLAGS%%|${CFLAGS:C/(.*)/'\1',/}| ; \
			s|%%CXXFLAGS%%|${CXXFLAGS:C/(.*)/'\1',/}| ; \
			s|%%LDFLAGS%%|${LDFLAGS:C/(.*)/'\1',/}| ; \
			s|%%QT_BINDIR%%|${QT_BINDIR}| ; \
			s|%%QT_INCDIR%%|${QT_INCDIR}| ; \
			s|%%QT_LIBDIR%%|${QT_LIBDIR}| ; \
			s|%%QMAKESPEC%%|${QMAKESPEC}| ; \
			s|%%PYTHON_CMD%%|${PYTHON_CMD}|" \
		${FILESDIR}/gyp-patches | \
		${PATCH} -z .bak -s)
	@${ECHO} "#define FREEBSD_QT_PLUGINDIR \"${QT_PLUGINDIR}\"" > ${WRKSRC}/Telegram/SourceFiles/FREEBSD_QT_PLUGINDIR.h

pre-configure:
	@cd ${WRKSRC} && gyp \
	    -Dbuild_defines=${GYP_DEFINES} \
	    -Gconfig=Release \
	    --depth=Telegram/gyp --generator-output=../.. -Goutput_dir=out Telegram/gyp/Telegram.gyp --format=cmake
	@TOT=`wc -l < ${WRKSRC}/out/Release/CMakeLists.txt` && NUM=`expr $$TOT - 2` && \
	    ${SED} -i -e "$$NUM r ${FILESDIR}/CMakeLists.inj" ${WRKSRC}/out/Release/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/Telegram ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/xdg/telegramdesktop.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/kservices5
	${INSTALL_DATA} ${WRKSRC}/lib/xdg/tg.protocol ${STAGEDIR}${PREFIX}/share/kservices5
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/appdata
	${INSTALL_DATA} ${WRKSRC}/lib/xdg/telegramdesktop.appdata.xml ${STAGEDIR}${PREFIX}/share/appdata/${PORTNAME}.appdata.xml
.for icon_size in 16 32 48 64 128 256 512
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${icon_size}x${icon_size}/apps
	${INSTALL_DATA} \
		${WRKSRC}/Telegram/Resources/art/icon${icon_size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${icon_size}x${icon_size}/apps/${PORTNAME}.png
.endfor

.include <bsd.port.post.mk>
