# $FreeBSD$

# QtWebEngine itself is a very thin layer of Qt code on top of a large part of
# Chromium (everything up to the content/ layer). As such, most of the work in
# this port revolves around taming Chromium and getting it to build on FreeBSD.
# While it does build at the moment, there are several items that should be
# investigated or improved:
# - We are using several stub files, especially in Chromium's base/ and net/
#   layers. We should look at implementing the missing bits instead.
# - We are currently not using any sandboxing mechanism.
# - We are disabling support for features such as WebRTC and printing. We need
#   to see what it would take to properly support them.
# - We need to see if more "use_system_<FOO>" flags can be passed.
# - The process of porting QtWebEngine needs to be documented so we can move to
#   newer releases more easily.

PORTNAME=	webengine
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	3
CATEGORIES=	www
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 library to render web content

BUILD_DEPENDS=	bison:devel/bison \
		ninja:devel/ninja \
		yasm:devel/yasm \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libdbus-1.so:devel/dbus \
		libevent.so:devel/libevent \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjsoncpp.so:devel/jsoncpp \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libopus.so:audio/opus \
		libpci.so:devel/libpci \
		libpng.so:graphics/png \
		libre2.so:devel/re2 \
		libsnappy.so:archivers/snappy \
		libsrtp.so:net/libsrtp \
		libwebp.so:graphics/webp

OPTIONS_SINGLE=		AUDIO
OPTIONS_SINGLE_AUDIO=	ALSA PULSEAUDIO
OPTIONS_DEFAULT=	ALSA

AUDIO_DESC=		Audio backend

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_QMAKE_ON=		QT_CONFIG+=alsa
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_QMAKE_ON=	QT_CONFIG+=pulseaudio

# We pass `norecursive' to USES=qmake because src/plugins/plugins.pro checks
# whether webenginewidgets is available, which fails when qmake processes all
# .pro files at once.
USES=		gperf jpeg python:2.7,build pkgconfig \
		qmake:norecursive,outsource shebangfix
USE_GNOME=	glib20 libxml2 libxslt
USE_QT5=	core designer gui location network qml quick webchannel \
		widgets buildtools_build qmake_build
USE_XORG=	scrnsaverproto x11 xcb xcomposite xcursor xext xi xproto \
		xrandr xrender xscrnsaver xtst

USE_LDCONFIG=	${QT_LIBDIR}

QT_DIST=	${PORTNAME}

QMAKE_CONFIGURE_ARGS=	-no-printing-and-pdf -proprietary-codecs -system-ffmpeg

# We could just set it to an empty string as well. "all" does not account for
# dependencies correctly in the generated Makefiles, use the right target here.
ALL_TARGET=	first

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-10

BUILD_DEPENDS+=	clang50:devel/llvm50
CC=		clang50
CXX=		clang++50
.endif  # ${OPSYS} == FreeBSD && ${OSVERSION} < 1100000

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

post-extract:
# Install FreeBSD's freebsd.pri file.
	${CP} ${FILESDIR}/freebsd.pri ${WRKSRC}/src/core/config/freebsd.pri

pre-configure:
# Link in ${PYTHON_CMD} to ${CONFIGURE_WRKSRC}/bin -- the scripts hardcode 'python'
# in too many places to reasonably patch. So just link in ${PYTHON_CMD} to work around
# $LOCALBASE/bin/python being python3 if the default versions is set to 3.x.
	${MKDIR} ${CONFIGURE_WRKSRC}/bin && ${LN} -s ${PYTHON_CMD} ${CONFIGURE_WRKSRC}/bin/python
# Unbundle a few dependencies.
	${PYTHON_CMD} ${WRKSRC}/src/3rdparty/chromium/build/linux/unbundle/replace_gn_files.py \
		--system-libraries libwebp libxml libxslt yasm

.include <bsd.port.post.mk>
