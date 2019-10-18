# $FreeBSD$

PORTNAME=	telegram-desktop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.15
CATEGORIES=	net-im

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Telegram Desktop messaging app

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	Only little endian is supported

BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib \
		dee>0:devel/dee \
		gyp:devel/py-gyp@${PY_FLAVOR} \
		pulseaudio>0:audio/pulseaudio \
		range-v3>0:devel/range-v3
LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libdbus-1.so:devel/dbus \
		libminizip.so:archivers/minizip \
		libopenal.so:audio/openal-soft \
		libopus.so:audio/opus

USES=		cmake:noninja compiler:c++17-lang desktop-file-utils gmake \
		gnome pkgconfig python:2.7,build qt:5 ssl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	telegramdesktop
GH_PROJECT=	tdesktop
GH_TUPLE=	catchorg:Catch2:5ca44b68:catch/Telegram/ThirdParty/Catch \
		mapbox:variant:550ac2f:variant/Telegram/ThirdParty/variant \
		Microsoft:GSL:d846fe5:gsl/Telegram/ThirdParty/GSL \
		telegramdesktop:libtgvoip:d4a0f71:libtgvoip/Telegram/ThirdParty/libtgvoip \
		telegramdesktop:crl:52baf11:crl/Telegram/ThirdParty/crl \
		Cyan4973:xxHash:7cc9639:xxhash/Telegram/ThirdParty/xxHash \
		john-preston:rlottie:589db02:rlottie/Telegram/ThirdParty/rlottie \
		lz4:lz4:9a2a9f2:lz4/Telegram/ThirdParty/lz4
USE_GNOME=	glib20
USE_QT=		core dbus gui imageformats network widgets buildtools_build \
		qmake_build
USE_XORG=	x11 xcb

CMAKE_SOURCE_PATH=	${WRKSRC}/out/Release

# Telegram asks each custom build to have its own API ID and hash.
# Use the default ones for now. We may need to switch to the official ones,
# or create our own.
TELEGRAM_API_ID=	17349
TELEGRAM_API_HASH=	344583e45741c457fe1862106095a5eb
GYP_DEFINES=		TDESKTOP_DISABLE_CRASH_REPORTS,TDESKTOP_DISABLE_AUTOUPDATE,TDESKTOP_DISABLE_REGISTER_CUSTOM_SCHEME

# Telegram uses OpenAL for its audio, but libtgvoip (for voice calls) can use PulseAudio or ALSA.
# It dynamically loads PulseAudio, and if this fails, it loads ALSA.
# If both of them are not installed, then voice calls do not work, but other functionalities still work.
OPTIONS_MULTI=		AUDIO
OPTIONS_MULTI_AUDIO=	ALSA PULSEAUDIO
OPTIONS_DEFINE=		GTK
OPTIONS_DEFAULT=	ALSA

AUDIO_DESC=	Audio backend for voice calls
GTK_DESC=	Gtk integration (Use Gtk dialogs, etc.)

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK}
USE_GNOME+=	gtk30
.else
GYP_DEFINES:=	${GYP_DEFINES},TDESKTOP_DISABLE_GTK_INTEGRATION
.endif

.include <bsd.port.pre.mk>

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
	@${REINPLACE_CMD} "/Icon=/s|telegram|${PORTNAME}|" ${WRKSRC}/lib/xdg/telegramdesktop.desktop

pre-configure:
	@cd ${WRKSRC} && gyp \
	    -Dapi_id=${TELEGRAM_API_ID} \
	    -Dapi_hash=${TELEGRAM_API_HASH} \
	    -Dbuild_defines=${GYP_DEFINES} \
	    -Gconfig=Release \
	    --depth=Telegram/gyp --generator-output=../.. -Goutput_dir=out Telegram/gyp/Telegram.gyp --format=cmake
	@TOT=`wc -l < ${WRKSRC}/out/Release/CMakeLists.txt` && NUM=`expr $$TOT - 2` && \
	    ${REINPLACE_CMD} "$$NUM r ${FILESDIR}/CMakeLists.inj" ${WRKSRC}/out/Release/CMakeLists.txt

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
