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
# This is the parent port of print/qt6-pdf. Please always keep 'PORTREVISION?='
# and reset the value to '0' only after increasing QT6_VERSION in Mk/Uses/qt.mk.
PORTREVISION?=	0
CATEGORIES?=	www
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT?=	Qt 6 library to render web content

# 32-bit platforms are not supported by upstream, but we're limping them along.
ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		${PYTHON_PKGNAMEPREFIX}cyclonedx-python-lib>0:textproc/py-cyclonedx-python-lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spdx-tools>=0.8.3:misc/py-spdx-tools@${PY_FLAVOR}
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libnss3.so:security/nss \
		libopenjp2.so:graphics/openjpeg \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++20-lang gl localbase:ldflags ninja:build \
		pkgconfig python:build qt-dist:6,webengine
USE_GL=		opengl
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}
USE_QT=		base declarative tools
USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xkbfile \
		xrandr xrender xscrnsaver xshmfence xtst

CONFIGURE_ENV=	NODEJS_EXECUTABLE="${LOCALBASE}/bin/node"

CMAKE_ARGS=	-DQWELibClang_BIN_PATH="${LOCALBASE}/bin"
CMAKE_ON=	QT_FEATURE_webengine_system_ffmpeg \
		QT_FEATURE_webengine_proprietary_codecs
CMAKE_OFF=	QT_FEATURE_webengine_precompiled_headers

.if defined(BUILD_QTPDF)
CMAKE_ON+=	QT_FEATURE_qtpdf_build
CMAKE_OFF+=	QT_FEATURE_qtwebengine_build

SYS_LIBS=	freetype
.else
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR}
LIB_DEPENDS+=	libabsl_base.so:devel/abseil \
		libavcodec.so:multimedia/ffmpeg \
		libdbus-1.so:devel/dbus \
		libdrm.so:graphics/libdrm \
		libepoll-shim.so:devel/libepoll-shim \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz \
		liblcms2.so:graphics/lcms2 \
		libnspr4.so:devel/nspr \
		libopenh264.so:multimedia/openh264 \
		libopus.so:audio/opus \
		libpci.so:devel/libpci \
		libpng.so:graphics/png \
		libre2.so:devel/re2 \
		libsnappy.so:archivers/snappy \
		libtiff.so:graphics/tiff \
		libudev.so:devel/libudev-devd \
		libvpx.so:multimedia/libvpx \
		libwebp.so:graphics/webp

USES+=		bison gnome gperf jpeg minizip xorg
USE_GL+=	gbm
USE_QT+=	positioning quick3d:build webchannel
USE_GNOME+=	glib20 libxml2 libxslt
USE_XORG+=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xkbfile \
		xrandr xrender xscrnsaver xshmfence xtst

CMAKE_ON+=	QT_FEATURE_qtwebengine_build
CMAKE_OFF+=	QT_FEATURE_qtpdf_build

CXXFLAGS+=	-I${LOCALBASE}/include/libepoll-shim

SYS_LIBS=	freetype harfbuzz-ng libdrm libpng libxml libxslt openh264 opus
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

BINARY_ALIAS=	git=false python3=${PYTHON_CMD}

.if !defined(BUILD_QTPDF)
OPTIONS_DEFINE=		DRIVER PIPEWIRE RUST
OPTIONS_DEFAULT=	ALSA DRIVER PIPEWIRE
OPTIONS_SINGLE=		AUDIO
OPTIONS_SINGLE_AUDIO=	ALSA PULSEAUDIO SNDIO
OPTIONS_SUB=		yes

AUDIO_DESC=		Audio backend

# Need the alsa plugins to get sound at runtime, otherwise messages
# that the pcm_oss plugin can't be opened.
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	alsa-plugins>=0:audio/alsa-plugins
ALSA_CMAKE_ON=		-DQT_FEATURE_webengine_system_alsa:BOOL=ON
ALSA_CMAKE_OFF=		-DQT_FEATURE_webengine_system_alsa:BOOL=OFF

DRIVER_DESC=		Install WebEngineDriver
DRIVER_CMAKE_ON=	-DQT_FEATURE_webenginedriver:BOOL=ON
DRIVER_CMAKE_OFF=	-DQT_FEATURE_webenginedriver:BOOL=OFF

PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CMAKE_ON=	-DQT_FEATURE_webengine_webrtc_pipewire:BOOL=ON
PIPEWIRE_CMAKE_OFF=	-DQT_FEATURE_webengine_webrtc_pipewire:BOOL=OFF

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_ON=	-DQT_FEATURE_webengine_system_pulseaudio:BOOL=ON
PULSEAUDIO_CMAKE_OFF=	-DQT_FEATURE_webengine_system_pulseaudio:BOOL=OFF

RUST_DESC=		Build with Rust (experimental)
RUST_BROKEN=		doesn't link
RUST_BUILD_DEPENDS=	bindgen:devel/rust-bindgen-cli \
			rustc:lang/rust
RUST_USES=		llvm:lib,noexport
RUST_CMAKE_BOOL=	QT_FEATURE_webengine_rust_build

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_ON=		-DQT_FEATURE_webengine_system_sndio:BOOL=ON
SNDIO_CMAKE_OFF=	-DQT_FEATURE_webengine_system_sndio:BOOL=OFF
.endif

.include <bsd.port.options.mk>

.if !defined(BUILD_QTPDF)
.  if ${ARCH:Mi386}
USES+=		nodejs:build,20
.  else
USES+=		nodejs:build,lts
.  endif
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/src/3rdparty/chromium/media/audio/sndio \
		${WRKSRC}/src/3rdparty/chromium/sandbox/policy/freebsd \
		${WRKSRC}/src/3rdparty/chromium/sandbox/policy/openbsd
	(cd ${WRKSRC}/src/3rdparty/chromium/third_party/libdrm/src/include && ${CP} drm/drm.h .)

post-patch:
	@${REINPLACE_CMD} -e 's|%%CPPFLAGS%%|${CPPFLAGS}|;s|%%CXXFLAGS%%|${CXXFLAGS}|;s|%%LDFLAGS%%|${LDFLAGS}|' \
		${WRKSRC}/src/host/BUILD.toolchain.gn.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/src/3rdparty/chromium/third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp \
		${WRKSRC}/src/3rdparty/chromium/ui/events/ozone/layout/xkb/xkb_keyboard_layout_engine.cc
.if defined(LLVM_VERSION)
	@${REINPLACE_CMD} -e 's|%%LLVM_VERSION%%|${LLVM_VERSION}' \
		${WRKSRC}/cmake/FindQWELibClang.cmake
.else
	@${REINPLACE_CMD} -e 's|%%LLVM_VERSION%%||' \
		${WRKSRC}/cmake/FindQWELibClang.cmake
.endif

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

.if !defined(BUILD_QTPDF)
post-install:
# Fix for deskutils/calibre, perhaps others, where this empty directory
# is created during build causing a fs-violation.
	${MKDIR} ${STAGEDIR}${QT_DATADIR}/resources/locales

post-install-DRIVER-on:
	${STRIP_CMD} ${STAGEDIR}${QT_TOOLDIR}/webenginedriver

.endif

# Update/create a mid-cycle security patch for the chromium sources and generate VuXML.
# To run faster, apply for an NVD API key: https://nvd.nist.gov/developers/request-an-api-key
# and call target with NVD_API_KEY=<your_api_key> or set NVD_API_KEY=<your_api_key> in
# /etc/make.conf or set it in your environment.
qtwebengine-create-security-patch:
	@${ECHO_CMD} "===> Updating/creating mid-cycle security patch..."
	@if ! command -v git >/dev/null 2>&1; then \
	    ${ECHO_CMD} "ERROR: 'git' is not installed or not in PATH. Please install devel/git."; \
	    exit 1; \
	fi; \
	${ECHO_CMD} "====> Determining base qtwebengine-chromium submodule hash from qtwebengine tag v${DISTVERSION}..."; \
	tmp_repo=$$(${MKTEMP} -d -t qtwebengine_repo); \
	cd "$${tmp_repo}" && git init --quiet && \
	git fetch --depth 1 --quiet https://code.qt.io/qt/qtwebengine.git "refs/tags/v${DISTVERSION}:refs/tags/v${DISTVERSION}" && \
	base_hash=$$(git ls-tree refs/tags/v${DISTVERSION} src/3rdparty | ${AWK} '{print $$3}'); \
	cd - >/dev/null; \
	${RM} -rf "$${tmp_repo}"; \
	if [ -z "$${base_hash}" ]; then \
	    ${ECHO_CMD} "ERROR: Could not determine base qtwebegine-chromium submodule hash from qtwebengine tag v${DISTVERSION}."; \
	    exit 1; \
	fi; \
	${ECHO_CMD} "====> Using qtwebengine-chromium base hash: $${base_hash}"; \
	${ECHO_CMD} "====> Determining qtwebengine-chromium branch..."; \
	chromium_major=$$(${FETCH_CMD} -q -o - "https://code.qt.io/cgit/qt/qtwebengine-chromium.git/plain/chromium/chrome/VERSION?id=$${base_hash}" | ${AWK} -F= '/^MAJOR/ {print $$2}' | ${TR} -d '\r'); \
	if [ -z "$${chromium_major}" ]; then \
	    ${ECHO_CMD} "ERROR: Could not determine Chromium major version."; \
	    exit 1; \
	fi; \
	chromium_branch="$${chromium_major}-based"; \
	${ECHO_CMD} "====> Using qtwebengine-chromium branch: $${chromium_branch}"; \
	${ECHO_CMD} "====> Fetching security rollup patch from $${base_hash} to $${chromium_branch}..."; \
	tmp_patch=$$(${MKTEMP} -t qt_sec_patch); \
	if ! ${FETCH_CMD} -o "$${tmp_patch}" "https://code.qt.io/cgit/qt/qtwebengine-chromium.git/rawdiff/?id=$${chromium_branch}&id2=$${base_hash}" >/dev/null 2>&1; then \
	    ${ECHO_CMD} "ERROR: Could not fetch diff from https://code.qt.io/cgit/."; \
	    ${RM} -f "$${tmp_patch}"; \
	    exit 1; \
	fi; \
	${ECHO_CMD} "====> Formatting patch paths and adding header..."; \
	( \
	    ${PRINTF} "Base-Commit: $${base_hash}\nBranch: $${chromium_branch}\n\n"; \
	    ${SED} -E \
	      -e 's|^(--- )a/|\1src/3rdparty/|' \
	      -e 's|^(\+\+\+ )b/|\1src/3rdparty/|' \
	      "$${tmp_patch}" \
	) > ${.CURDIR}/files/patch-security-rollup; \
	${RM} -f "$${tmp_patch}"; \
	${ECHO_CMD} "===> Updated ${FILESDIR}/patch-security-rollup"; \
	if [ -f "${FILESDIR}/generate-vuxml-entry.py" ]; then \
	    current_year=$$(date +%Y); \
	    vuxml_file="${.CURDIR:H:H}/security/vuxml/vuln/$${current_year}.xml"; \
	    ${ECHO_CMD} "===> Generating VuXML entry in $${vuxml_file}..."; \
	    tmp_vuxml=$$(${MKTEMP} -t qt_vuxml); \
	    ${SETENV} NVD_API_KEY=${NVD_API_KEY} ${PYTHON_CMD} ${FILESDIR}/generate-vuxml-entry.py -f "$${vuxml_file}" "$${base_hash}" "$${chromium_branch}" "${PKGVERSION}" > "$${tmp_vuxml}"; \
	    if [ -s "$${tmp_vuxml}" ]; then \
	        if [ -f "$${vuxml_file}" ]; then \
	            ${ECHO_CMD} "====> Prepending entry to $${vuxml_file}..."; \
	            ${CAT} "$${tmp_vuxml}" "$${vuxml_file}" > "$${vuxml_file}.new"; \
	            ${MV} "$${vuxml_file}.new" "$${vuxml_file}"; \
	        else \
	            ${ECHO_CMD} "====> Warning: $${vuxml_file} not found. Saving to ${.CURDIR}/vuxml_entry.xml instead. Maybe it's the new year and security/vuxml needs to be updated?"; \
	            ${MV} "$${tmp_vuxml}" ${.CURDIR}/vuxml_entry.xml; \
	        fi; \
	    else \
	        ${RM} -f "$${tmp_vuxml}"; \
	    fi; \
	else \
	    ${ECHO_CMD} "====> Warning: ${FILESDIR}/generate-vuxml-entry.py not found. Skipping VuXML generation."; \
	fi

.include <bsd.port.mk>
