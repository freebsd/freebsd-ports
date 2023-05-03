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
# Also note that, due to the insane amount of patches this port needs, it tends
# to lag behind the rest of the official Qt6 ones, which is why we set
# QT6_VERSION and DISTINFO_FILE here.

PORTNAME=	webengine
DISTVERSION=	${QT6_VERSION}
PORTREVISION=	6
CATEGORIES=	www
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 library to render web content

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR} \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libdbus-1.so:devel/dbus \
		libevent.so:devel/libevent \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		liblcms2.so:graphics/lcms2 \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libopenh264.so:multimedia/openh264 \
		libopus.so:audio/opus \
		libpci.so:devel/libpci \
		libpng.so:graphics/png \
		libre2.so:devel/re2 \
		libsnappy.so:archivers/snappy \
		libvpx.so:multimedia/libvpx \
		libwebp.so:graphics/webp \
		libxkbcommon.so:x11/libxkbcommon

USES=	bison cmake gl gnome gperf jpeg localbase:ldflags minizip ninja:build \
	nodejs:build,lts pkgconfig python:build qt-dist:6,webengine xorg
USE_GL=		gl
USE_GNOME=	glib20 libxml2 libxslt
USE_QT=		base declarative:run positioning quick3d:build webchannel
USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xkbfile \
		xrandr xrender xscrnsaver xshmfence xtst

CMAKE_ON=	QT_FEATURE_webengine_system_ffmpeg QT_FEATURE_webengine_proprietary_codecs

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

BINARY_ALIAS=	python=${PYTHON_CMD}

# Add extra-patch-no-mempcpy-nasm only when there's no mempcpy() in base.
# Nested variable expansion avoids executing the test when not needed for
# expanding EXTRA_PATCHES.
# mempcpy was introduced in ee37f64cf875255338f917a9da76c643cf59786c
EXTRA_PATCHES+=	${"${:!${GREP} mempcpy ${CROSS_SYSROOT}/usr/include/string.h \
		|| ${TRUE}!}" == "":?${PATCHDIR}/extra-patch-no-mempcpy-nasm:}

DISTINFO_FILE=	${.CURDIR}/distinfo
QT6_VERSION=	6.4.2

OPTIONS_DEFAULT=	ALSA
OPTIONS_SINGLE=		AUDIO
OPTIONS_SINGLE_AUDIO=	ALSA PULSEAUDIO SNDIO

AUDIO_DESC=		Audio backend

# Need the alsa plugins to get sound at runtime, otherwise messages
# that the pcm_oss plugin can't be opened.
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	alsa-plugins>=0:audio/alsa-plugins
ALSA_CMAKE_ON=		-DQT_FEATURE_webengine_system_alsa:BOOL=ON
ALSA_CMAKE_OFF=		-DQT_FEATURE_webengine_system_alsa:BOOL=OFF
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_ON=	-DQT_FEATURE_webengine_system_pulseaudio:BOOL=ON
PULSEAUDIO_CMAKE_OFF=	-DQT_FEATURE_webengine_system_pulseaudio:BOOL=OFF
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_ON=		-DQT_FEATURE_webengine_system_sndio:BOOL=ON
SNDIO_CMAKE_OFF=	-DQT_FEATURE_webengine_system_sndio:BOOL=OFF

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 || ${ARCH} == armv7
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-32bit-compress_files_js
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/src/3rdparty/chromium/media/audio/sndio \
		${WRKSRC}/src/3rdparty/chromium/sandbox/policy/freebsd \
		${WRKSRC}/src/3rdparty/chromium/sandbox/policy/openbsd

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|%%CPPFLAGS%%|${CPPFLAGS}|;s|%%CXXFLAGS%%|${CXXFLAGS}|;s|%%LDFLAGS%%|${LDFLAGS}|' \
		${WRKSRC}/src/host/BUILD.toolchain.gn.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/src/3rdparty/chromium/third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp \
		${WRKSRC}/src/3rdparty/chromium/third_party/wayland/features.gni \
		${WRKSRC}/src/3rdparty/chromium/ui/events/ozone/layout/xkb/xkb_keyboard_layout_engine.cc

pre-configure:
# We used to remove bundled libraries to be sure that webengine uses
# system libraries and not shipped ones.
#
# Leads to missing header errors: icu, libvpx, libwebp, re2, snappy, zlib
# No-Op: flac
#
# cd ${WRKSRC} && ${PYTHON_CMD} \
# ./build/linux/unbundle/remove_bundled_libraries.py [list of preserved]
	cd ${WRKSRC}/src/3rdparty/chromium && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		./build/linux/unbundle/replace_gn_files.py --system-libraries \
		fontconfig freetype harfbuzz-ng libdrm libevent libpng libxml libxslt openh264 opus || ${FALSE}

.include <bsd.port.post.mk>
