# $FreeBSD$

# QtWebEngine itself is a very thin layer of Qt code on top of a large part of
# Chromium (everything up to the content/ layer). As such, most of the work in
# this port revolves around taming Chromium and getting it to build on FreeBSD.
# While it does build at the moment, there are several items that should be
# investigated or improved:
# - We are using several stub files, especially in Chromium's base/ and net/
#   layers. We should look at implementing the missing bits instead.
# - We are currently not using any sandboxing mechanism.
# - We need to see if more "use_system_<FOO>" flags can be passed.
# - The process of porting QtWebEngine needs to be documented so we can move to
#   newer releases more easily.
#
# Also note that, due to the insane amount of patches this port needs, it tends
# to lag behind the rest of the official Qt5 ones, which is why we set
# QT5_VERSION and DISTINFO_FILE here.

PORTNAME=	webengine
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	2
CATEGORIES=	www
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 library to render web content

BUILD_DEPENDS=	bison:devel/bison \
		ninja:devel/ninja \
		yasm:devel/yasm \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libdbus-1.so:devel/dbus \
		libdouble-conversion.so:devel/double-conversion \
		libevent.so:devel/libevent \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjsoncpp.so:devel/jsoncpp \
		liblcms2.so:graphics/lcms2 \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libopus.so:audio/opus \
		libpci.so:devel/libpci \
		libpng.so:graphics/png \
		libre2.so:devel/re2 \
		libsnappy.so:archivers/snappy \
		libvpx.so:multimedia/libvpx \
		libwebp.so:graphics/webp

DISTINFO_FILE=	${.CURDIR}/distinfo
QT5_VERSION=	5.15.2

OPTIONS_SINGLE=		AUDIO
OPTIONS_SINGLE_AUDIO=	ALSA PULSEAUDIO SNDIO
OPTIONS_DEFAULT=	ALSA

AUDIO_DESC=		Audio backend

# Need the alsa plugins to get sound at runtime, otherwise messages
# that the pcm_oss plugin can't be opened.
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	alsa-plugins>=0:audio/alsa-plugins
ALSA_VARS=		QMAKE_CONFIGURE_ARGS+=-alsa
ALSA_VARS_OFF=		QMAKE_CONFIGURE_ARGS+=-no-alsa
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_VARS=	QMAKE_CONFIGURE_ARGS+=-pulseaudio
PULSEAUDIO_VARS_OFF=	QMAKE_CONFIGURE_ARGS+=-no-pulseaudio
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_VARS=		QMAKE_CONFIGURE_ARGS+=-sndio
SNDIO_VARS_OFF=		QMAKE_CONFIGURE_ARGS+=-no-sndio

# We pass `norecursive' to USES=qmake because src/plugins/plugins.pro checks
# whether webenginewidgets is available, which fails when qmake processes all
# .pro files at once.
USES=		gl gnome gperf jpeg python:2.7,build pkgconfig \
		qmake:norecursive,outsource qt-dist:5,webengine shebangfix xorg
USE_GL=		gl
USE_GNOME=	glib20 libxml2 libxslt
USE_QT=		core declarative gui location network printsupport \
		webchannel widgets \
		buildtools_build designer_build qmake_build
USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xorgproto \
		xrandr xrender xscrnsaver xtst

QMAKE_CONFIGURE_ARGS=	-proprietary-codecs -system-ffmpeg

# We could just set it to an empty string as well. "all" does not account for
# dependencies correctly in the generated Makefiles, use the right target here.
ALL_TARGET=	first

# We need ar(1) from ports because the Chromium code uses the @file syntax.
# We then need to ensure ld(1) from ports is used because of the archives ar(1)
# generated.
USE_BINUTILS=	yes
CC+=		"-B${LOCALBASE}/bin"
CXX+=		"-B${LOCALBASE}/bin"

# The build system reads the environment variable $NINJA_PATH to decide whether
# to boostrap ninja or not (and also to invoke it afterwards). CC and CXX are
# read by some Chromium code to determine which compiler to invoke when running
# some configuration tests.
# Since we use USES=qmake:norecursive, we also need to pass some variables to
# MAKE_ENV because part of the configuration process happens during the build.
CONFIGURE_ENV+=	NINJAFLAGS="-j${MAKE_JOBS_NUMBER}" \
		NINJA_PATH="${LOCALBASE}/bin/ninja"  \
		PATH=${CONFIGURE_WRKSRC}/bin:${LOCALBASE}/bin:${PATH}
MAKE_ENV+=	CC="${CC}" CXX="${CXX}"			\
		C_INCLUDE_PATH=${LOCALBASE}/include	\
		CPLUS_INCLUDE_PATH=${LOCALBASE}/include	\
		${CONFIGURE_ENV}

QT_BINARIES=	yes

.include <bsd.port.pre.mk>

.if ${ARCH:Mmips*} || ${ARCH:Mpowerpc*} || ${ARCH} == sparc64
PLIST_SUB+=	BE="" LE="@comment "
.else
PLIST_SUB+=	BE="@comment " LE=""
.endif

post-extract:
# Install FreeBSD's freebsd.pri file.
	${CP} ${FILESDIR}/freebsd.pri ${WRKSRC}/src/buildtools/config/freebsd.pri

post-extract-SNDIO-on:
	@cd ${WRKSRC}/src/3rdparty/chromium/media/audio && ${MKDIR} sndio openbsd
	@${CP} ${FILESDIR}/sndio_*put.* \
		${WRKSRC}/src/3rdparty/chromium/media/audio/sndio
	@${CP} ${FILESDIR}/audio_manager_openbsd.* \
		${WRKSRC}/src/3rdparty/chromium/media/audio/openbsd

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/src/3rdparty/chromium/base/linux_util.cc \
		${WRKSRC}/src/3rdparty/chromium/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/src/3rdparty/chromium/chrome/common/chrome_paths.cc \
		${WRKSRC}/src/3rdparty/chromium/third_party/pdfium/core/fxge/fx_ge_linux.cpp \
		${WRKSRC}/src/3rdparty/chromium/third_party/pdfium/xfa/fgas/font/cfx_fontsourceenum_file.cpp \
		${WRKSRC}/src/3rdparty/gn/build/gen.py

.if ${ARCH:Mmips*} || ${ARCH:Mpowerpc*} || ${ARCH} == sparc64
	@${REINPLACE_CMD} -e 's/icudtl.dat/icudtb.dat/' \
		${WRKSRC}/src/core/core_module.pro
.endif

pre-configure:
# Link in ${PYTHON_CMD} to ${CONFIGURE_WRKSRC}/bin -- the scripts hardcode 'python'
# in too many places to reasonably patch. So just link in ${PYTHON_CMD} to work around
# $LOCALBASE/bin/python being python3 if the default versions is set to 3.x.
	${MKDIR} ${CONFIGURE_WRKSRC}/bin && ${LN} -s ${PYTHON_CMD} ${CONFIGURE_WRKSRC}/bin/python
# Unbundle a few dependencies.
	${PYTHON_CMD} ${WRKSRC}/src/3rdparty/chromium/build/linux/unbundle/replace_gn_files.py \
		--system-libraries libwebp libxml libxslt yasm
# Rerun syncqt.pl -- otherwise the resulting package misses some forwarding headers.
	cd ${WRKSRC} && ${QT_BINDIR}/syncqt.pl -version ${QT5_VERSION}

.include <bsd.port.post.mk>
