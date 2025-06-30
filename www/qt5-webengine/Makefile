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

# In order to successfully build this port in poudriere you need to add
# MAX_FILES_qt5_webengine=4096 to /usr/local/etc/poudriere.conf

PORTNAME=	webengine
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 library to render web content

BUILD_DEPENDS=	bison:devel/bison \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR}
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
		libopenh264.so:multimedia/openh264 \
		libopus.so:audio/opus \
		libpci.so:devel/libpci \
		libpng.so:graphics/png \
		libre2.so:devel/re2 \
		libsnappy.so:archivers/snappy \
		libvpx.so:multimedia/libvpx \
		libwebp.so:graphics/webp

DISTINFO_FILE=	${.CURDIR}/distinfo
QT5_VERSION=	${_KDE_webengine_VERSION}

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
USES=		gl gnome gperf jpeg minizip ninja:build nodejs:build,lts \
		perl5 pkgconfig python:build qmake:norecursive,outsource \
		qt-dist:5,webengine shebangfix xorg
USE_GL=		gl
USE_GNOME=	glib20 libxml2 libxslt
USE_PERL5=	build
USE_QT=		core declarative gui location network printsupport \
		webchannel widgets \
		buildtools:build designer:build qmake:build
USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xkbfile \
		xorgproto xrandr xrender xscrnsaver xtst
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

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

.if ${ARCH:Mmips*} || ${ARCH:Mpowerpc*}
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
		${WRKSRC}/src/3rdparty/chromium/base/test/BUILD.gn \
		${WRKSRC}/src/3rdparty/chromium/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/src/3rdparty/chromium/chrome/common/chrome_paths.cc \
		${WRKSRC}/src/3rdparty/chromium/third_party/pdfium/core/fxge/fx_ge_linux.cpp \
		${WRKSRC}/src/3rdparty/gn/build/gen.py
	@${REINPLACE_CMD} -E -e 's|^(MODULE_VERSION = ).*|\1${QT5_VERSION}|' \
		${WRKSRC}/.qmake.conf

.if ${ARCH:Mmips*} || ${ARCH:Mpowerpc*}
	@${REINPLACE_CMD} -e 's/icudtl.dat/icudtb.dat/' \
		${WRKSRC}/src/core/core_module.pro
.endif

pre-configure:
# Link in ${PYTHON_CMD} to ${CONFIGURE_WRKSRC}/bin -- the scripts hardcode 'python'
# in too many places to reasonably patch. So just link in ${PYTHON_CMD} to work around
# $LOCALBASE/bin/python being python3 if the default versions is set to 3.x.
	${MKDIR} ${CONFIGURE_WRKSRC}/bin && ${LN} -s ${PYTHON_CMD} ${CONFIGURE_WRKSRC}/bin/python
# Unbundle a few dependencies.
	cd ${WRKSRC}/src/3rdparty/chromium && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		./build/linux/unbundle/replace_gn_files.py --system-libraries\
		fontconfig freetype harfbuzz-ng libdrm libevent libpng libwebp libxml libxslt openh264 opus || ${FALSE}
# Rerun syncqt.pl -- otherwise the resulting package misses some forwarding headers.
	cd ${WRKSRC} && ${QT_BINDIR}/syncqt.pl -version ${QT5_VERSION}

post-build:
# Fix version mismatches for CMake
.for module in Pdf PdfWidgets WebEngine WebEngineCore WebEngineWidgets
	@${REINPLACE_CMD} -e '/${QT5_VERSION} $${_Qt5${module}_FIND_VERSION_EXACT}/s|${QT5_VERSION}|'"$$(${MAKE} -C ../../devel/qt5-core -VQT5_VERSION)"'|' \
		${BUILD_WRKSRC}/lib/cmake/Qt5${module}/Qt5${module}Config.cmake
.endfor

post-install:
	for lib in ${STAGEDIR}${PREFIX}/${QT_LIBDIR_REL}/*.so.${_QT_VERSION:C/-.*//} ; \
	do \
		${BRANDELF} -t FreeBSD $$lib ; \
	done

.include <bsd.port.post.mk>
