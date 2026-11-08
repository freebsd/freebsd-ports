PORTNAME=	cef
DISTVERSION=	152.0.6
PORTREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	https://commondatastorage.googleapis.com/chromium-browser-official/:chromium
DISTFILES=	chromium-${CHROMIUM_VERSION}-lite${EXTRACT_SUFX}:chromium

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Chromium Embedded Framework
WWW=		https://github.com/chromiumembedded/cef

LICENSE=	BSD3CLAUSE LGPL21 MPL11
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/cef/LICENSE.txt

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	the Chromium build is only supported on amd64 and aarch64

# CEF is Chromium with an embedding API on top, and each CEF branch is tied to
# one Chromium release, see cef/CHROMIUM_BUILD_COMPATIBILITY.txt.  This is the
# release that CEF 152.0.6 (branch 7977) was built against upstream.
CHROMIUM_VERSION=	152.0.7977.83

# The CEF tools compute the version string (152.0.6+g708dc14+chromium-...)
# from the Git history of the CEF repository.  The distfile has none, so the
# values they would find there are passed to them through the environment,
# see files/patch-cef_tools_cef__version.py:
# - the commit this port is built from,
# - its position in the history ("git rev-list --count"),
# - the number of commits on the release branch, which is the patch level of
#   the CEF version.
CEF_COMMIT=		708dc140cbc3286826a8abef89dc23a44ff9ea72
CEF_COMMIT_NUMBER=	3589
CEF_BRANCH_PATCH=	${DISTVERSION:E}

# This port builds natively, like www/chromium: depot_tools, gclient and the
# CEF automate-git.py script are not used.  The Chromium release tarball
# already contains all DEPS-managed third-party code, and the CEF sources are
# added below src/cef, where gclient would put them.
USE_GITHUB=	nodefault
GH_TUPLE=	chromiumembedded:cef:${CEF_COMMIT}:cef/cef \
		rollup:rollup:v4.60.4:rollup/rollup \
		evanw:esbuild:v${_ESBUILD_VERSION:sh}:esbuild/esbuild

# Chromium builds devtools-frontend with rollup and esbuild.  Neither ships a
# FreeBSD binary, so the rollup native binding is built from source (like
# www/chromium does, hence the shared Makefile.crates) and esbuild is taken
# from ports.
_ESBUILD_VERSION=	${MAKE} -C ${PORTSDIR}/devel/esbuild -V DISTVERSION

WRKSRC=		${WRKDIR}/chromium-${CHROMIUM_VERSION}

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		${LOCALBASE}/include/va/va.h:multimedia/libva \
		${LOCALBASE}/libdata/pkgconfig/dri.pc:graphics/mesa-libs \
		${LOCALBASE}/share/usbids/usb.ids:misc/usbids \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
		bash:shells/bash \
		bindgen:devel/rust-bindgen-cli \
		esbuild:devel/esbuild \
		flock:sysutils/flock \
		gperf:devel/gperf \
		rustc:lang/rust \
		xcb-proto>0:x11/xcb-proto

LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-core \
		libatspi.so:accessibility/at-spi2-core \
		libcairo.so:graphics/cairo \
		libdav1d.so:multimedia/dav1d \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libdrm.so:graphics/libdrm \
		libepoll-shim.so:devel/libepoll-shim \
		libevent.so:devel/libevent \
		libexif.so:graphics/libexif \
		libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi \
		libFLAC.so:audio/flac \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgcrypt.so:security/libgcrypt \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libharfbuzz.so:print/harfbuzz \
		libicuuc.so:devel/icu \
		libjsoncpp.so:devel/jsoncpp \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libopenh264.so:multimedia/openh264 \
		libopus.so:audio/opus \
		libpci.so:devel/libpci \
		libpng.so:graphics/png \
		libre2.so:devel/re2 \
		libsecret-1.so:security/libsecret \
		libspeechd.so:accessibility/speech-dispatcher \
		libspeex.so:audio/speex \
		libwayland-client.so:graphics/wayland \
		libwebp.so:graphics/webp \
		libxkbcommon.so:x11/libxkbcommon \
		libxshmfence.so:x11/libxshmfence

USES=		bison cargo cmake:indirect compiler:c++20-lang gl gmake gnome \
		go:no_targets iconv:wchar_t jpeg localbase:ldflags ninja \
		nodejs:build perl5 pkgconfig python:build tar:xz xorg

CARGO_CARGOTOML=	${WRKSRC}/rollup/rust/Cargo.toml
CARGO_CARGOLOCK=	${WRKSRC}/rollup/rust/Cargo.lock
CARGO_TARGET_DIR=	${WRKSRC}/rollup/rust/target
CARGO_INSTALL=		No
CARGO_BUILD=		No
CARGO_TEST=		No
# MAKE_ENV carries DESTDIR=${STAGEDIR}; the cmake install run by the
# libmimalloc-sys2 build script honours it and would drop its OUT_DIR
# (headers, libmimalloc.a, cmake/pkgconfig files) into the stage directory.
CARGO_ENV+=		DESTDIR=

USE_GL=		gbm gl
USE_GNOME=	atk dconf gdkpixbuf glib20 gtk30 libxml2 libxslt
USE_LDCONFIG=	${PREFIX}/${CEFDIR}/Release
USE_PERL5=	build
USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xorgproto \
		xrandr xrender xscrnsaver xtst

# Everything is installed in the layout of a CEF binary distribution, which is
# what CEF clients such as multimedia/obs-studio look for (CEF_ROOT_DIR).
CEFDIR=		lib/${PORTNAME}
PLIST_SUB+=	CEFDIR=${CEFDIR}

# make_distrib.py expects the output directory of automate-git.py.
BUILDTYPE=	Release_GN_${GN_CPU}
MAKE_ARGS=	-C out/${BUILDTYPE}
# Besides libcef.so a CEF binary distribution carries what it needs at run
# time.  Those are only data_deps of libcef, which ninja does not build for the
# libcef target, so they are listed here, as is the credits page that
# make_distrib.py wants.
ALL_TARGET=	libcef \
		chrome:packed_resources \
		components/resources:about_credits \
		third_party/angle:libEGL \
		third_party/angle:libGLESv2 \
		third_party/icu:icudata \
		third_party/vulkan-loader/src:libvulkan \
		tools/v8_context_snapshot

BINARY_ALIAS=	python3=${PYTHON_CMD}

# Run "./out/${BUILDTYPE}/gn args out/${BUILDTYPE} --list" for all variables.
# The first block matches www/chromium, the second one holds the values that
# the CEF build normally gets from cef/tools/gn_args.py.
GN_ARGS+=	clang_use_chrome_plugins=false \
		enable_backup_ref_ptr_support=false \
		enable_remoting=false \
		enable_widevine=true \
		fatal_linker_warnings=false \
		is_clang=true \
		optimize_webui=true \
		toolkit_views=true \
		treat_warnings_as_errors=false \
		use_allocator_shim=false \
		use_aura=true \
		use_custom_libcxx=true \
		use_custom_libunwind=true \
		use_lld=true \
		use_partition_alloc=true \
		use_partition_alloc_as_malloc=false \
		use_sysroot=false \
		use_system_freetype=false \
		use_system_harfbuzz=true \
		use_system_libffi=true \
		use_system_libjpeg=true \
		use_udev=false \
		extra_cxxflags="${CXXFLAGS} -I${LOCALBASE}/include/libepoll-shim" \
		extra_ldflags="${LDFLAGS}" \
		ffmpeg_branding="${FFMPEG_BRAND}"
GN_ARGS+=	blink_heap_inside_shared_library=true \
		blink_symbol_level=0 \
		chrome_pgo_phase=0 \
		disable_fieldtrial_testing_config=true \
		enable_background_mode=false \
		enable_downgrade_processing=false \
		enable_linux_installer=false \
		enable_precompiled_headers=false \
		enable_resource_allowlist_generation=false \
		forbid_non_component_debug_builds=false \
		icu_use_data_file=true \
		is_component_build=false \
		is_debug=false \
		is_official_build=true \
		symbol_level=0 \
		use_qt5=false \
		use_qt6=false \
		use_unified_system_module=false

GN_BOOTSTRAP_FLAGS=	--no-clean --no-rebuild --skip-generate-buildfiles

OPTIONS_DEFINE=		CODECS CUPS KERBEROS LTO PIPEWIRE
OPTIONS_DEFAULT=	ALSA CODECS CUPS KERBEROS PIPEWIRE PULSEAUDIO SNDIO
OPTIONS_EXCLUDE_aarch64=	LTO
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA PULSEAUDIO SNDIO
CODECS_DESC=		Compile and enable patented codecs like H.264
PIPEWIRE_DESC=		Screen capture via PipeWire

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_VARS=		GN_ARGS+=use_alsa=true
ALSA_VARS_OFF=		GN_ARGS+=use_alsa=false

CODECS_VARS=		FFMPEG_BRAND="Chrome" \
			GN_ARGS+=proprietary_codecs=true
CODECS_VARS_OFF=	FFMPEG_BRAND="Chromium" \
			GN_ARGS+=proprietary_codecs=false

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_VARS=		GN_ARGS+=use_cups=true
CUPS_VARS_OFF=		GN_ARGS+=use_cups=false

# SPNEGO and Negotiate authentication.  Chromium loads the GSSAPI library at
# run time, so the one in the base system serves and there is nothing to
# depend on.
KERBEROS_VARS=		GN_ARGS+=use_kerberos=true
KERBEROS_VARS_OFF=	GN_ARGS+=use_kerberos=false

LTO_VARS=		GN_ARGS+=thin_lto_enable_optimizations=true \
			GN_ARGS+=use_thin_lto=true
LTO_VARS_OFF=		GN_ARGS+=use_thin_lto=false

PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_VARS=		GN_ARGS+=rtc_link_pipewire=true \
			GN_ARGS+=rtc_use_pipewire=true
PIPEWIRE_VARS_OFF=	GN_ARGS+=rtc_link_pipewire=false \
			GN_ARGS+=rtc_use_pipewire=false

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_VARS=	GN_ARGS+=use_pulseaudio=true
PULSEAUDIO_VARS_OFF=	GN_ARGS+=use_pulseaudio=false

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_VARS=		GN_ARGS+=use_sndio=true
SNDIO_VARS_OFF=		GN_ARGS+=use_sndio=false

.include "Makefile.crates"

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

LLVM_DEFAULT=	22
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
# The CEF tools run clang to compute the API hashes and clang-format on the
# sources they generate, see files/patch-cef_tools_clang__util.py.
BINARY_ALIAS+=	ar=${LOCALBASE}/bin/llvm-ar${LLVM_DEFAULT} \
		c++=${LOCALBASE}/bin/clang++${LLVM_DEFAULT} \
		cc=${LOCALBASE}/bin/clang${LLVM_DEFAULT} \
		clang=${LOCALBASE}/bin/clang${LLVM_DEFAULT} \
		clang-format=${LOCALBASE}/bin/clang-format${LLVM_DEFAULT} \
		cpp=${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT} \
		ld=${LOCALBASE}/bin/ld.lld${LLVM_DEFAULT} \
		nm=${LOCALBASE}/bin/llvm-nm${LLVM_DEFAULT}

.if ${ARCH} == aarch64
GN_CPU=			arm64
CEF_DISTRIB_ARCH=	--arm64-build
FFMPEG_TARGET=		arm64
# swiftshader/lib/{libEGL.so,libGLESv2.so} is x86 only
PLIST_SUB+=		NOT_AARCH64="@comment "
.else
BUILD_DEPENDS+=		nasm:devel/nasm
ALL_TARGET+=		third_party/swiftshader/src/Vulkan:icd_file \
			third_party/swiftshader/src/Vulkan:swiftshader_libvulkan
GN_CPU=			x64
CEF_DISTRIB_ARCH=	--x64-build
FFMPEG_TARGET=		x64
PLIST_SUB+=		NOT_AARCH64=""
.endif

GN_ARGS+=	target_cpu="${GN_CPU}"

GN=		${WRKSRC}/out/${BUILDTYPE}/gn

FFMPEG_BDIR=	${WRKSRC}/third_party/ffmpeg/build.${FFMPEG_TARGET}.freebsd/${FFMPEG_BRAND}
FFMPEG_CDIR=	${WRKSRC}/third_party/ffmpeg/chromium/config/${FFMPEG_BRAND}/freebsd/${FFMPEG_TARGET}

# The binary distribution is assembled here by cef/tools/make_distrib.py.
DISTRIB_DIR=	${WRKDIR}/distrib/cef_minimal

MAKE_ENV+=	C_INCLUDE_PATH=${LOCALBASE}/include \
		CPLUS_INCLUDE_PATH=${LOCALBASE}/include \
		CEF_TARBALL_BRANCH_PATCH=${CEF_BRANCH_PATCH} \
		CEF_TARBALL_COMMIT_HASH=${CEF_COMMIT} \
		CEF_TARBALL_COMMIT_NUMBER=${CEF_COMMIT_NUMBER} \
		GOCACHE=${WRKDIR}/go-cache \
		PYTHONUNBUFFERED=1 \
		RUSTC_BOOTSTRAP=1
CONFIGURE_ENV+=	${MAKE_ENV}

GN_ARGS+=	enable_rust=true \
		rust_sysroot_absolute="${LOCALBASE}"

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "To build ${PORTNAME}, you should have at least:"
	@${ECHO_MSG} "- 16 GB of memory"
	@${ECHO_MSG} "- 60 GB of free disk space"
	@${ECHO_MSG} "- 1.5 million free inodes"
	@${ECHO_MSG}
	@${ECHO_MSG} "This build will use ${MAKE_JOBS_NUMBER} parallel job(s)."
	@${ECHO_MSG} "Linking libcef.so takes several gigabytes of memory, so on a"
	@${ECHO_MSG} "machine with more cores than memory set MAKE_JOBS_NUMBER_LIMIT"
	@${ECHO_MSG} "in /etc/make.conf rather than letting every core link at once."
	@${ECHO_MSG}

# The CEF patches are written against pristine Chromium, so they have to go in
# before the FreeBSD patches in files/, which the regular patch phase applies
# right after this target.  Those FreeBSD patches are the ones from
# www/chromium, and the few of them that touch the same lines as CEF have been
# rewritten to apply on top of the CEF changes.
#
# cef/patch/patch.cfg lists the CEF patches (it is what cef/tools/patcher.py
# works from).  It is read with awk: Python is only a build dependency and is
# not installed yet in this phase.
pre-patch:
	@${ECHO_MSG} "===>  Applying CEF patches to the Chromium tree"
	@${AWK} -f ${FILESDIR}/cef-patches.awk ${WRKSRC}/cef/patch/patch.cfg \
		> ${WRKDIR}/cef-patches
	@if [ ! -s ${WRKDIR}/cef-patches ]; then \
		${ECHO_MSG} "===>  No patches found in cef/patch/patch.cfg"; \
		${FALSE}; \
	fi
	@while read _name _path; do \
		${PATCH} -s -E -p0 -V none --forward -d ${WRKSRC}/$${_path} \
		    -i ${WRKSRC}/cef/patch/patches/$${_name}.patch || exit 1; \
	done < ${WRKDIR}/cef-patches

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		./build/linux/unbundle/replace_gn_files.py --system-libraries \
		dav1d flac fontconfig harfbuzz libdrm libpng \
		libusb libwebp libxml libxslt openh264 opus || ${FALSE}
# Chromium ships an unreleased FFmpeg, so its config has to be generated
	cd ${WRKSRC}/media/ffmpeg && \
		${PYTHON_CMD} scripts/build_ffmpeg.py freebsd ${FFMPEG_TARGET} \
		--config-only --branding=${FFMPEG_BRAND}
	cd ${FFMPEG_BDIR} && ${GMAKE} ffversion.h
	${MKDIR} ${FFMPEG_CDIR}
.for _e in config.h config.asm config_components.asm config_components.h \
	libavcodec libavformat libavutil
	-${CP} -pR ${FFMPEG_BDIR}/${_e} ${FFMPEG_CDIR}
.endfor
	@${REINPLACE_CMD} -e 's|$${LOCALBASE}|${LOCALBASE}|;s|$${MODCLANG_VERSION}|${LLVM_DEFAULT}|' \
		${WRKSRC}/build/linux/strip_binary.gni \
		${WRKSRC}/build/rust/rust_bindgen.gni \
		${WRKSRC}/build/rust/rust_bindgen_generator.gni
# What gclient_hook.py would do: generate the translated CEF sources (the C API
# headers, the C++/C glue in libcef_dll and cef_paths.gypi, which BUILD.gn
# reads) and the hashes of the unversioned API.
	cd ${WRKSRC}/cef && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		tools/version_manager.py -u --fast-check

pre-build:
# The rollup plugin devtools-frontend loads is a native node module
	@${CARGO_CARGO_RUN} build --manifest-path ${CARGO_CARGOTOML} \
		${CARGO_BUILD_ARGS}
	(cd ${WRKSRC}/third_party/devtools-frontend/src/node_modules/@rollup && \
		${MKDIR} rollup-freebsd && \
		${CP} ${CARGO_TARGET_DIR}/release/libbindings_napi.so \
			rollup-freebsd/rollup.freebsd.node && \
		${ECHO_CMD} '{ "main": "./rollup.freebsd.node" }' \
			> rollup-freebsd/package.json)

do-configure:
	(cd ${WRKSRC}/esbuild && \
		${LOCALBASE}/bin/node scripts/esbuild.js \
		${LOCALBASE}/bin/esbuild --neutral && \
		${RM} -r ${WRKSRC}/third_party/devtools-frontend/src/node_modules/esbuild && \
		${LN} -sf ${WRKSRC}/esbuild/npm/esbuild \
		${WRKSRC}/third_party/devtools-frontend/src/node_modules/esbuild)
	${LN} -sf ${LOCALBASE}/bin/esbuild \
		${WRKSRC}/third_party/devtools-frontend/src/third_party/esbuild/esbuild

# gn itself is built from the Chromium tree, no prebuilt binary is fetched
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} CC=${CC} CXX=${CXX} \
		LD=${CXX} READELF=${READELF} AR=${AR} NM=${NM} ${PYTHON_CMD} \
		./tools/gn/bootstrap/bootstrap.py -j${MAKE_JOBS_NUMBER} \
		--build-path=out/${BUILDTYPE} ${GN_BOOTSTRAP_FLAGS}

# Dependencies Chromium normally expects below third_party/
	@${MKDIR} ${WRKSRC}/third_party/node/freebsd/node-freebsd/bin
	${LN} -sf ${LOCALBASE}/bin/node \
		${WRKSRC}/third_party/node/freebsd/node-freebsd/bin/node
	@${MKDIR} ${WRKSRC}/third_party/rust-toolchain/bin
	${LN} -sf ${LOCALBASE}/bin/rustc \
		${WRKSRC}/third_party/rust-toolchain/bin/rustc
	${LN} -sf ${LOCALBASE}/bin/gperf \
		${WRKSRC}/third_party/gperf/cipd/bin/gperf
	@${MKDIR} ${WRKSRC}/buildtools/freebsd
	${LN} -sf ${WRKSRC}/buildtools/linux64/clang-format \
		${WRKSRC}/buildtools/freebsd
	${LN} -sf ${GN} ${WRKSRC}/buildtools/freebsd
	${LN} -sf /usr/bin/strip ${WRKSRC}/buildtools/freebsd/strip

	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GN} gen \
		--args='${GN_ARGS}' out/${BUILDTYPE}

post-build:
# The www/chromium patches drop -z defs on BSD, so libcef.so links even when it
# still refers to code that the FreeBSD build leaves out.  It then fails to
# load (OBS opens its plugins with RTLD_NOW) and the loader names only the
# first missing symbol.  libcef.so carries its own libc++, so every C++ symbol
# it refers to has to be defined in it: list all that are not.
	@${LOCALBASE}/bin/llvm-nm${LLVM_DEFAULT} -D --undefined-only \
		${WRKSRC}/out/${BUILDTYPE}/libcef.so | \
		${AWK} '$$1 == "U" && $$2 ~ /^_Z/ { print $$2 }' \
		> ${WRKDIR}/libcef-undefined
	@if [ -s ${WRKDIR}/libcef-undefined ]; then \
		${ECHO_MSG} "===>  libcef.so refers to C++ symbols it does not define:"; \
		c++filt < ${WRKDIR}/libcef-undefined; \
		${FALSE}; \
	fi
# Lay the build out as a CEF binary distribution: the headers (including the
# generated ones), the sources and CMake files of libcef_dll_wrapper, and the
# binaries and resources.  --allow-partial because there is no Debug build.
	@${RM} -r ${WRKDIR}/distrib
	cd ${WRKSRC}/cef && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		tools/make_distrib.py --output-dir=${WRKDIR}/distrib \
		--distrib-subdir=cef --allow-partial --minimal --ninja-build \
		${CEF_DISTRIB_ARCH} --no-archive --no-docs --no-format \
		--no-symbols --quiet
# libcef_dll_wrapper is a static library that CEF clients link against.  It
# has to be compiled like those clients are, with the base system compiler and
# its libc++ instead of the private libc++ that libcef.so is built with (the
# two only talk to each other through the C API), so it is built with the
# CMake files of the binary distribution.
	${SETENV} ${MAKE_ENV} \
		${CMAKE_BIN} -S ${DISTRIB_DIR} -B ${DISTRIB_DIR}/build -G Ninja \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_C_COMPILER=/usr/bin/cc \
		-DCMAKE_CXX_COMPILER=/usr/bin/c++ \
		-DCMAKE_MAKE_PROGRAM=${NINJA_CMD}
	${SETENV} ${MAKE_ENV} \
		${NINJA_CMD} -C ${DISTRIB_DIR}/build ${_MAKE_JOBS} \
		libcef_dll_wrapper

# The runtime files go into one directory, Release/: CEF looks for its
# resources, locales, ICU data and V8 snapshot next to libcef.so (it overrides
# DIR_ASSETS with the directory it was loaded from) and so does ANGLE.
# Resources/ is kept as a link for clients that use the CMake files of the
# distribution.  The Vulkan loader is installed as libvulkan.so because that is
# the name the FreeBSD patches make Chromium load it by (see www/chromium).
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${CEFDIR}
	cd ${DISTRIB_DIR} && ${COPYTREE_SHARE} \
		"CMakeLists.txt CREDITS.html LICENSE.txt README.txt cmake include \
		libcef_dll" ${STAGEDIR}${PREFIX}/${CEFDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${CEFDIR}/Release
.for _f in libcef.so libEGL.so libGLESv2.so
	${INSTALL_LIB} ${DISTRIB_DIR}/Release/${_f} \
		${STAGEDIR}${PREFIX}/${CEFDIR}/Release
.endfor
	${INSTALL_LIB} ${DISTRIB_DIR}/Release/libvulkan.so.1 \
		${STAGEDIR}${PREFIX}/${CEFDIR}/Release/libvulkan.so
	${INSTALL_DATA} ${DISTRIB_DIR}/Release/v8_context_snapshot.bin \
		${STAGEDIR}${PREFIX}/${CEFDIR}/Release
.if ${ARCH} != aarch64
	${INSTALL_LIB} ${DISTRIB_DIR}/Release/libvk_swiftshader.so \
		${STAGEDIR}${PREFIX}/${CEFDIR}/Release
	${INSTALL_DATA} ${DISTRIB_DIR}/Release/vk_swiftshader_icd.json \
		${STAGEDIR}${PREFIX}/${CEFDIR}/Release
.endif
	cd ${DISTRIB_DIR}/Resources && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/${CEFDIR}/Release
	${RLN} ${STAGEDIR}${PREFIX}/${CEFDIR}/Release \
		${STAGEDIR}${PREFIX}/${CEFDIR}/Resources
	@${MKDIR} ${STAGEDIR}${PREFIX}/${CEFDIR}/libcef_dll_wrapper
	${INSTALL_DATA} \
		${DISTRIB_DIR}/build/libcef_dll_wrapper/libcef_dll_wrapper.a \
		${STAGEDIR}${PREFIX}/${CEFDIR}/libcef_dll_wrapper

.include <bsd.port.post.mk>
