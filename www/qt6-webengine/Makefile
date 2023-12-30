# QtWebEngine itself is a very thin layer of Qt code on top of a large part of
# Chromium (everything up to the content/ layer). As such, most of the work in
# this port revolves around taming Chromium and getting it to build on FreeBSD.
# While it does build at the moment, there are several items that should be
# investigated or improved:
# - We are using several stub files, especially in Chromium's base/ and net/
#   layers. We should look at implementing the missing bits instead.
# - We are currently not using any sandboxing mechanism.
# - The process of porting QtWebEngine needs to be documented so we can move to
#   newer releases more easily.
#

PORTNAME?=	webengine
DISTVERSION=	${QT6_VERSION}
PORTREVISION?=	1 # Master port for print/qt6-pdf. Please keep this line.
CATEGORIES?=	www
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT?=	Qt 6 library to render web content

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR} \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libnss3.so:security/nss \
		libxkbcommon.so:x11/libxkbcommon

USES=		bison cmake compiler:c++17-lang gl gperf \
		localbase:ldflags ninja:build nodejs:build,lts \
		pkgconfig python:build qt-dist:6,webengine
USE_GL=		opengl
USE_QT=		base declarative tools
USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xkbfile \
		xrandr xrender xscrnsaver xshmfence xtst

CMAKE_ON=	QT_FEATURE_webengine_system_ffmpeg \
		QT_FEATURE_webengine_proprietary_codecs

.if defined(BUILD_QTPDF)
LIB_DEPENDS+=	libcups.so:print/cups \
		libopenjp2.so:graphics/openjpeg

CMAKE_ON+=	QT_FEATURE_qtpdf_build
CMAKE_OFF+=	QT_FEATURE_qtwebengine_build

SYS_LIBS=	freetype
.else
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS+=	libavcodec.so:multimedia/ffmpeg \
		libdbus-1.so:devel/dbus \
		libdrm.so:graphics/libdrm \
		libevent.so:devel/libevent \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz \
		libnspr4.so:devel/nspr \
		libopenh264.so:multimedia/openh264 \
		libopus.so:audio/opus \
		libpci.so:devel/libpci \
		libpng.so:graphics/png \
		libre2.so:devel/re2 \
		libsnappy.so:archivers/snappy \
		libvpx.so:multimedia/libvpx \
		libwebp.so:graphics/webp

USES+=		gnome jpeg minizip xorg
USE_GL+=	gbm
USE_QT+=	positioning quick3d:build webchannel
USE_GNOME+=	glib20 libxml2 libxslt
USE_XORG+=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xkbfile \
		xrandr xrender xscrnsaver xshmfence xtst

CMAKE_ON+=	QT_FEATURE_qtwebengine_build
CMAKE_OFF+=	QT_FEATURE_qtpdf_build

SYS_LIBS=	freetype harfbuzz-ng libdrm libevent libpng libxml libxslt openh264 opus
.endif

# The build system reads the environment variable $NINJA_PATH to decide whether
# to boostrap ninja or not (and also to invoke it afterwards). CC and CXX are
# read by some Chromium code to determine which compiler to invoke when running
# some configuration tests.
CONFIGURE_ENV+=	NINJAFLAGS="-j${MAKE_JOBS_NUMBER}" \
		NINJA_PATH="${LOCALBASE}/bin/ninja"  \
		PATH=${CONFIGURE_WRKSRC}/bin:${LOCALBASE}/bin:${PATH}
MAKE_ENV+=	CC="${CC}" CXX="${CXX}"			\
		C_INCLUDE_PATH=${LOCALBASE}/include	\
		CPLUS_INCLUDE_PATH=${LOCALBASE}/include	\
		${CONFIGURE_ENV}
# Avoid running multiple make(1) jobs, but only those.  Otherwise the build
# fails intermittently due race conditions if multiple ninja instances are
# running at the same time (mostly for the targets "WebEngineCore" and
# "convert_dict").
#
# MAKE_JOBS_UNSAFE is too invasive because it also affects the number of jobs
# for ninja(1) and would slow everything down which we don't want.  We pass the
# real number of make jobs via MAKE_JOBS_NUMBER to ninja(1) to CONFIGURE_ENV.
DO_MAKE_BUILD=	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} -j1 ${MAKE_ARGS:N${DESTDIRNAME}=*}

BINARY_ALIAS=	python3=${PYTHON_CMD}

.if !defined(BUILD_QTPDF)
OPTIONS_DEFINE=		CUPS
OPTIONS_DEFAULT=	ALSA CUPS
OPTIONS_SINGLE=		AUDIO
OPTIONS_SINGLE_AUDIO=	ALSA PULSEAUDIO SNDIO

AUDIO_DESC=		Audio backend

# Need the alsa plugins to get sound at runtime, otherwise messages
# that the pcm_oss plugin can't be opened.
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	alsa-plugins>=0:audio/alsa-plugins
ALSA_CMAKE_ON=		-DQT_FEATURE_webengine_system_alsa:BOOL=ON
ALSA_CMAKE_OFF=		-DQT_FEATURE_webengine_system_alsa:BOOL=OFF

CUPS_LIB_DEPENDS=	libcups.so:print/cups \
			liblcms2.so:graphics/lcms2 \
			libopenjp2.so:graphics/openjpeg \
			libtiff.so:graphics/tiff
CUPS_CMAKE_ON=		-DQT_FEATURE_webengine_printing_and_pdf:BOOL=ON
CUPS_CMAKE_OFF=		-DQT_FEATURE_webengine_printing_and_pdf:BOOL=OFF

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_ON=	-DQT_FEATURE_webengine_system_pulseaudio:BOOL=ON
PULSEAUDIO_CMAKE_OFF=	-DQT_FEATURE_webengine_system_pulseaudio:BOOL=OFF

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_ON=		-DQT_FEATURE_webengine_system_sndio:BOOL=ON
SNDIO_CMAKE_OFF=	-DQT_FEATURE_webengine_system_sndio:BOOL=OFF
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 || ${ARCH} == armv7
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-32bit-compress_files_js
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/src/3rdparty/chromium/media/audio/sndio \
		${WRKSRC}/src/3rdparty/chromium/sandbox/policy/freebsd \
		${WRKSRC}/src/3rdparty/chromium/sandbox/policy/openbsd

post-patch:
	@${REINPLACE_CMD} -e 's|%%CPPFLAGS%%|${CPPFLAGS}|;s|%%CXXFLAGS%%|${CXXFLAGS}|;s|%%LDFLAGS%%|${LDFLAGS}|' \
		${WRKSRC}/src/host/BUILD.toolchain.gn.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/src/3rdparty/chromium/third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp \
		${WRKSRC}/src/3rdparty/chromium/ui/events/ozone/layout/xkb/xkb_keyboard_layout_engine.cc

pre-configure:
# We used to remove bundled libraries to be sure that webengine uses
# system libraries and not shipped ones.
#
# Leads to missing header errors: icu, libvpx, libwebp, re2, snappy, zlib
# No-Op: flac
#
# Don't attempt to unbundle libraries that the Pdf module doesn't use. It
# causes configuration errors.
#
# cd ${WRKSRC} && ${PYTHON_CMD} \
# ./build/linux/unbundle/remove_bundled_libraries.py [list of preserved]
	cd ${WRKSRC}/src/3rdparty/chromium && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		./build/linux/unbundle/replace_gn_files.py --system-libraries \
		${SYS_LIBS} || ${FALSE}

.include <bsd.port.post.mk>
