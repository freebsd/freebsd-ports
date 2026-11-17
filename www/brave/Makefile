PORTNAME=	brave
DISTVERSIONPREFIX=	v
DISTVERSION=	1.97.59
TSV=		7.0.2
CATEGORIES=	www
MASTER_SITES=	https://github.com/chromium-linux-tarballs/chromium-tarballs/releases/download/${CHROME_VERSION}/:chromium \
		https://codeload.github.com/microsoft/TypeScript/tar.gz/v${TSV}?dummy=/:typescript \
		https://nerd.hu/distfiles/:external \
		${NODE_MODULES_SITE}:nodemods
DISTFILES=	${_CHROMIUM_DIST}:chromium \
		${_TS_DIST}:typescript \
		${_TS_VENDOR_DIST}:external

_CHROMIUM_DIST=		chromium-${CHROME_VERSION}-linux.tar.xz
_TS_DIST=		microsoft-TypeScript-v${TSV}_GH0.tar.gz
_TS_VENDOR_DIST=	TypeScript-${TSV}-vendor.tar.gz

# The extract phase ends with extract-fixup-modes, a recursive chmod(1) over
# all of WRKDIR, which fails on trees this large (the same problem
# podman-desktop works around).  So Chromium (675,000 entries), the TypeScript
# sources (140,000) and the Node modules (110,000) are left out of it and
# unpacked by pre-patch instead; their modes need no fixing.
EXTRACT_ONLY=	${DISTFILES:C/:[^:]+$//:N${_CHROMIUM_DIST}:N${_TS_DIST}:N${_TS_VENDOR_DIST}:N${NODE_MODULES_DIST}}

NODE_MODULES_DIST=	brave-node-modules-${DISTVERSION}.tar.xz
NODE_MODULES_SITE?=	https://github.com/Martinfx/FreeBSD-Ports/releases/download/brave-${DISTVERSION}/

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Brave web browser based on Chromium
WWW=		https://brave.com/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/src/brave/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	the Chromium build is only supported on amd64 and aarch64

# Chromium release the pinned brave-core revision is built against, see
# "config.projects.chrome.tag" in src/brave/package.json.  Brave 1.97.59 pins
# 155.0.8059.85, but no tarball has been published for it, so this takes .84,
# the closest one there is, from the same chromium-linux-tarballs project
# www/chromium fetches from.  Every brave-core 1.97.59 patch and every patch in
# files/ applies to it without fuzz.  Move to .85 once its tarball appears.
CHROME_VERSION=	155.0.8059.84

# The FreeBSD patches for the Chromium tree in files/ started out as the ones
# from www/chromium 154.0.8037.57, rewritten for the src/ prefix this port
# unpacks Chromium into.  www/chromium has not moved to 155 yet, so they have
# been carried forward to 155 here and regenerated against the tree as
# brave-core patches it.
#
# This port builds natively: depot_tools, gclient, cipd, siso and reclient are
# not used at all.  Everything is taken from a Chromium release tarball
# (which, unlike a git checkout, already contains all DEPS-managed
# third-party code), from brave-core and from the ports tree.  The parts that
# gclient would normally fetch for brave-core are listed in GH_TUPLE below and
# match the "deps" section of src/brave/DEPS.

USE_GITHUB=	yes
GH_ACCOUNT=	brave
GH_PROJECT=	brave-browser
GH_TUPLE=	brave:brave-core:v${DISTVERSION}:core/src/brave \
		brave-intl:bat-native-tweetnacl:8b424ccf29957fe01c88c36076fd32006a357887:tweetnacl/src/brave/vendor/bat-native-tweetnacl \
		brave:gn-project-generators:b76e14b162aa0ce40f11920ec94bfc12da29e5d0:gnprojgen/src/brave/vendor/gn-project-generators \
		brave:web-discovery-project:4b07a24d03ee1a266230d2ffb78fd390e35e262a:wdp/src/brave/vendor/web-discovery-project \
		brave-intl:bat-native-bip39wally-core:547a7810333d821e29b8f55126aba031aa0d5fcd:bip39wally/src/brave/third_party/bip39wally-core-native \
		chfast:ethash:e4a15c3d76dc09392c7efd3e30d84ee3b871e9ce:ethash/src/brave/third_party/ethash/src \
		bitcoin:bitcoin:8105bce5b384c72cf08b25b7c5343622754e7337:bitcoincore/src/brave/third_party/bitcoin-core/src \
		P-H-C:phc-winner-argon2:62358ba2123abd17fccf2a108a301d4b52c01a7c:argon2/src/brave/third_party/argon2/src \
		brave:playlist-component:673d40f017a1559bb685a15cf608ad1d4a94f8fb:playlist/src/brave/third_party/playlist_component/src \
		brave-intl:futures-retry:2aaaafbc3d394661534d4dbd14159d164243c20e:futuresretry/src/brave/third_party/rust/futures_retry/v0_5/crate \
		brave:librustzcash:f01f50d64214278552edbe4a34b9049244ce03c1:librustzcash/src/brave/components/brave_wallet/browser/zcash/rust/librustzcash/src \
		evanw:esbuild:v${_ESBUILD_VERSION:sh}:esbuild/src/esbuild

# Chromium builds devtools-frontend with esbuild, which ships no FreeBSD
# binary, so it is taken from ports.  (Up to 154 devtools-frontend also
# bundled with rollup, whose native binding had to be built from source; 155
# uses esbuild alone, and the WebUI bundles take @rollup/wasm-node.)
#
# Since 154 devtools-frontend also compiles its TypeScript with tsgo, the
# native TypeScript compiler, which Chromium gets from CIPD as a Linux binary
# (third_party/typescript/linux-amd64/src/lib/tsc).  It is built from the
# TypeScript sources instead (only tsc/, the Go implementation, is unpacked),
# with the Go modules it needs from a vendor tarball, the same way
# www/chromium does it.  Chromium's own WebUI keeps
# using the TypeScript in node_modules (use_typescript_go=false), and the
# tsc that its Python helpers look up in PATH comes from lang/typescript-go.
_ESBUILD_VERSION=	${MAKE} -C ${PORTSDIR}/devel/esbuild -V DISTVERSION

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		${LOCALBASE}/libdata/pkgconfig/dri.pc:graphics/mesa-libs \
		${LOCALBASE}/share/usbids/usb.ids:misc/usbids \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
		bash:shells/bash \
		bindgen:devel/rust-bindgen-cli \
		corepack>0:www/corepack \
		esbuild:devel/esbuild \
		flock:sysutils/flock \
		gperf:devel/gperf \
		libva>0:multimedia/libva \
		rustc:lang/rust \
		tsc:lang/typescript-go \
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

# No xdg-desktop-portal backend is depended on: screen sharing under Wayland
# needs the one that matches the desktop in use and nothing else, so
# pkg-message names them rather than pulling one in here.
RUN_DEPENDS=	noto-basic>0:x11-fonts/noto-basic \
		xdg-open:devel/xdg-utils

USES=		bison compiler:c++20-lang cpe desktop-file-utils gl gmake \
		gnome go:no_targets iconv:wchar_t jpeg localbase:ldflags ninja \
		nodejs:24,build perl5 pkgconfig python:build shebangfix tar:xz \
		xorg

CPE_VENDOR=	brave
CPE_PRODUCT=	brave
USE_GL=		gbm gl
USE_GNOME=	atk dconf gdkpixbuf glib20 gtk30 libxml2 libxslt
USE_LDCONFIG=	${DATADIR}
USE_PERL5=	build
USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xorgproto \
		xrandr xrender xscrnsaver xtst

SHEBANG_FILES=	src/brave/script/*.py

# Everything below out/ is driven by ninja from the Chromium source root.
BUILD_WRKSRC=		${WRKSRC}/src
CONFIGURE_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=		${WRKSRC}/src
MAKE_ARGS=		-C \
			out/${BUILDTYPE}
ALL_TARGET=		brave

BINARY_ALIAS=	python3=${PYTHON_CMD}

BRAVE_VERSION_MAJOR=	${DISTVERSION:R:R}
BRAVE_VERSION_MINOR=	${DISTVERSION:R:E}
BRAVE_VERSION_BUILD=	${DISTVERSION:E}

GN=			${BUILD_WRKSRC}/out/${BUILDTYPE}/gn
GN_BOOTSTRAP_FLAGS=	--no-clean --no-rebuild --skip-generate-buildfiles

# Brave overrides Chromium sources through chromium_src/: a compile whose
# source has a counterpart there is handed that file instead.  Since 1.97 siso
# does this by itself (brave/build/config/siso/brave_siso_config.star), and
# siso is fetched with CIPD and does not exist for FreeBSD, so the compiler is
# run through files/redirect_cc.c as a cc_wrapper, which does the same.
REDIRECT_CC=	${WRKDIR}/redirect_cc

_LEO=		${WRKSRC}/src/brave/node_modules/@brave/leo

# brave-core takes @brave/leo straight from git, and pnpm prepares such a
# package by running a "pnpm install" of its own in it and then its "prepare"
# script, "pnpm run build", which runs further pnpm commands.  pnpm starts all
# of those through the shell, by name, but corepack only offers pnpm as
# "corepack pnpm": without a pnpm in PATH the install fails with
# ERR_PNPM_PREPARE_PACKAGE.  So put one first in PATH, in BINARY_LINKDIR,
# that is just that.  Like corepack, it follows the packageManager field of
# the directory it runs in, leo's included.
#
# The install runs until leo is built rather than only while node_modules is
# missing, so that a run that failed half way is picked up again instead of
# leaving a partial node_modules behind for good.
_PNPM_INSTALL=	${MKDIR} ${BINARY_LINKDIR} && \
		${PRINTF} '\043!/bin/sh\nexec ${LOCALBASE}/bin/corepack pnpm "$$@"\n' \
		    > ${BINARY_LINKDIR}/pnpm && \
		${CHMOD} 755 ${BINARY_LINKDIR}/pnpm && \
		cd ${WRKSRC}/src/brave && ${SETENV} ${CONFIGURE_ENV} \
		    ${BINARY_LINKDIR}/pnpm install --frozen-lockfile

# Arguments that describe the platform and the toolchain.  Without them the
# build falls back to the Chromium defaults and pulls in things FreeBSD cannot
# build, such as the allocator shim, whose malloc overrides clash with the
# declarations in libc.
GN_BASE_ARGS=	target_os="freebsd" target_cpu="${GN_CPU}" \
		clang_use_chrome_plugins=false \
		enable_backup_ref_ptr_support=false enable_rust=true \
		fatal_linker_warnings=false is_clang=true \
		rust_sysroot_absolute="${LOCALBASE}" \
		treat_warnings_as_errors=false use_allocator_shim=false \
		use_custom_libcxx=true use_custom_libunwind=true use_lld=true \
		use_partition_alloc=true use_partition_alloc_as_malloc=false \
		use_reclient=false use_remoteexec=false use_siso=false \
		use_sysroot=false use_udev=false \
		extra_cxxflags="${CXXFLAGS} -I${LOCALBASE}/include/libepoll-shim" \
		extra_ldflags="${LDFLAGS}"

# Chromium turns dcheck_always_on on by itself whenever is_official_build is
# off, which is how Brave builds outside its own release pipeline.  It compiles
# every DCHECK in the tree plus V8's verification machinery into the binary --
# on the V8 files alone that is thirteen extra defines, among them
# V8_VERIFY_WRITE_BARRIERS, CPPGC_VERIFY_HEAP and V8_ENABLE_DEBUG_CODE -- and
# those checks abort the browser when they fire.  That is what upstream wants
# from a development build and not what a package wants, so turn it off: the
# build graph keeps the same ~58500 steps, but 45000 of them are compiles and
# every one of them gets cheaper.
# Brave sends this key as the BraveServiceKey header on every request to
# *.brave.com, see ShouldAddBraveServicesKeyHeader() in
# brave_services_key_helper.cc and AddBraveServicesKeyHeader() in
# brave_system_request_handler.cc.  Left empty, go-updater.brave.com answers
# 403 and not one component ever installs: no ad block filter list catalog, so
# no ad blocking at all, and no CRLSet either.  brave://components then shows
# every entry stuck at 0.0.0.0 with an update error.
#
# Brave issues the key to its own builds and has not said whether a build from
# source may carry one; Arch Linux ships the key from the official builds in
# its PKGBUILD with a TODO pointing at
# https://community.brave.com/t/does-brave-allow-the-distribution-of-self-compiled-or-distro-compiled-binaries
#
# Nothing else from that PKGBUILD is needed here: brave_variations_server_url,
# brave_sync_endpoint and updater_prod_endpoint already carry those values by
# default, brave_stats_updater_url defaults to a newer host than the one Arch
# sets, and the p3a and star_randomness arguments no longer exist.
BRAVE_SERVICES_KEY=	qjVKcxtUybh8WpKNoQ7EbgbkJTMu7omjDHKk=VrPApb8PwJyPE9eqchxedTsMEWg
# Only these three gate is_official_build, but they are read at run time
# regardless: SERVICE_KEY_SEARCH signs the requests to Brave Search, see
# brave_service_key_network_delegate_helper.cc, SERVICE_KEY_AICHAT goes to
# Leo and SERVICE_KEY_STT to speech to text.  Empty leaves those features
# talking to servers that will refuse them -- but so does a made up value,
# which only quiets the is_official_build assert while still being rejected
# at run time, so leave them empty until real ones turn up.
SERVICE_KEY_AICHAT=
SERVICE_KEY_SEARCH=
SERVICE_KEY_STT=
SERVICE_API_STATS=	fe033168-0ff8-4af6-9a7f-95e2cbfc9f4f
SERVER_URL=		https://variations.brave.com/seed

# Since 155 V8 generates its instance-types.h with metagen, which parses the
# V8 headers through libclang: the prebuilt libclang and its Python bindings
# come from CIPD (third_party/llvm-libclang), and the clang builtin headers
# are looked up in Chromium's own toolchain (third_party/llvm-build), neither
# of which exists here.  v8_use_metagen_instance_types=false takes the header
# Torque emits instead, which V8 still generates either way.
GN_ARGS+=	${GN_BASE_ARGS} \
		import("//brave/build/args/brave_defaults.gni") \
		import("//brave/build/args/blink_platform_defaults.gni") \
		import("//brave/build/args/branding_defaults.gni") \
		import("//brave/build/args/desktop_defaults.gni") \
		brave_channel="" \
		brave_services_key="${BRAVE_SERVICES_KEY}" \
		cc_wrapper="${REDIRECT_CC}" \
		chrome_pgo_phase=0 \
		dcheck_always_on=false \
		enable_cdm_host_verification=false \
		enable_hangout_services_extension=true \
		enable_remoting=false \
		enable_updater=false \
		enable_update_notifications=false \
		enable_web_discovery_native=false \
		icu_use_data_file=true \
		init_stack_vars_zero=true \
		is_component_build=false \
		is_official_build=false \
		optimize_webui=true \
		service_key_aichat="${SERVICE_KEY_AICHAT}" \
		service_key_search="${SERVICE_KEY_SEARCH}" \
		brave_stats_api_key="${SERVICE_API_STATS}" \
		brave_variations_server_url="${SERVER_URL}" \
		service_key_stt="${SERVICE_KEY_STT}" \
		skip_signing=true \
		toolkit_views=true \
		use_aura=true \
		use_qt5=false \
		use_system_freetype=false \
		use_system_harfbuzz=true \
		use_system_libffi=true \
		use_system_libjpeg=true \
		use_typescript_go=false \
		v8_use_metagen_instance_types=false \
		ffmpeg_branding="${FFMPEG_BRAND}" \
		brave_google_api_key="AIzaSyAREPLACEWITHYOUROWNGOOGLEAPIKEY2Q" \
		brave_google_api_endpoint="https://www.googleapis.com/geolocation/v1/geolocate?key="

OPTIONS_DEFINE=		CODECS CUPS DEBUG KERBEROS LTO NODEMODS PIPEWIRE QT6 \
			WIDEVINE
# NODEMODS is on by default so that the Node modules are fetched with the
# other distfiles and the build itself needs no network (poudriere has none).
# brave-node-modules-${DISTVERSION}.tar.xz has to be on NODE_MODULES_SITE
# and in distinfo for every version, see gen-node-modules.
OPTIONS_DEFAULT=	ALSA CODECS CUPS KERBEROS NODEMODS PIPEWIRE \
			PULSEAUDIO QT6 SNDIO WIDEVINE
OPTIONS_EXCLUDE_aarch64=	LTO
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA PULSEAUDIO SNDIO
OPTIONS_SUB=		yes
CODECS_DESC=		Compile and enable patented codecs like H.264
NODEMODS_DESC=		Fetch the Node modules as a distfile instead of running pnpm
PIPEWIRE_DESC=		Screen capture via PipeWire
WIDEVINE_DESC=		Depend on foreign-cdm to enable playback of DRM content

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_VARS=		GN_ARGS+=use_alsa=true
ALSA_VARS_OFF=		GN_ARGS+=use_alsa=false

CODECS_VARS=		FFMPEG_BRAND="Chrome" \
			GN_ARGS+=proprietary_codecs=true
CODECS_VARS_OFF=	FFMPEG_BRAND="Chromium" \
			GN_ARGS+=proprietary_codecs=false

# Chromium compiles the CUPS backend into the print stack; without the header
# the eight files under printing/backend that include <cups/...> do not build,
# which is why this carries a dependency and use_cups does not just ride its
# default.
CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_VARS=		GN_ARGS+=use_cups=true
CUPS_VARS_OFF=		GN_ARGS+=use_cups=false

DEBUG_VARS=	BUILDTYPE=Debug \
		GN_ARGS+=is_debug=true \
		GN_ARGS+=symbol_level=1 \
		GN_BOOTSTRAP_FLAGS+=--debug \
		WANTMEM="32 GB" \
		WANTSPACE="100 GB"
DEBUG_VARS_OFF=	BUILDTYPE=Release \
		GN_ARGS+=blink_symbol_level=0 \
		GN_ARGS+=is_debug=false \
		GN_ARGS+=symbol_level=0 \
		WANTMEM="16 GB" \
		WANTSPACE="60 GB"

# SPNEGO and Negotiate authentication.  Nothing in the build includes a GSSAPI
# header -- Chromium declares what it needs and loads the library at run time
# -- so the one in the base system serves and there is nothing to depend on.
KERBEROS_VARS=		GN_ARGS+=use_kerberos=true
KERBEROS_VARS_OFF=	GN_ARGS+=use_kerberos=false

LTO_VARS=	GN_ARGS+=thin_lto_enable_optimizations=true \
		GN_ARGS+=use_thin_lto=true
LTO_VARS_OFF=	GN_ARGS+=use_thin_lto=false

# Without this the modules are installed by pre-configure, which needs the
# network (in poudriere only with ALLOW_NETWORKING_PACKAGES); the distfile
# has to be regenerated whenever brave-core's pnpm-lock.yaml changes, so it
# carries the Brave version in its name.
NODEMODS_DISTFILES=	${NODE_MODULES_DIST}:nodemods

PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_VARS=		GN_ARGS+=rtc_link_pipewire=true \
			GN_ARGS+=rtc_use_pipewire=true
PIPEWIRE_VARS_OFF=	GN_ARGS+=rtc_link_pipewire=false \
			GN_ARGS+=rtc_use_pipewire=false

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_VARS=	GN_ARGS+=use_pulseaudio=true
PULSEAUDIO_VARS_OFF=	GN_ARGS+=use_pulseaudio=false

# Qt integration: libqt6_shim.so, which Brave dlopen()s from beside its own
# binary (DIR_MODULE, see ui/qt/qt_ui.cc) when the Qt toolkit is picked.
# Chromium runs moc itself, and without a path it looks the tool up in PATH,
# where Qt 6 does not put it: moc lives in QT_TOOLDIR (libexec/qt6).  The
# FreeBSD patch to ui/qt/moc_wrapper.py takes the path to the binary itself,
# not to its directory.
QT6_USES=		qt:6
QT6_USE=		QT=base
QT6_VARS=		GN_ARGS+=use_qt6=true \
			GN_ARGS+=moc_qt6_path="${QT_TOOLDIR}/moc"
QT6_VARS_OFF=		GN_ARGS+=use_qt6=false

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_VARS=		GN_ARGS+=use_sndio=true
SNDIO_VARS_OFF=		GN_ARGS+=use_sndio=false

# The Widevine CDM is not built here: enable_widevine only compiles the support
# for it, and www/foreign-cdm supplies the module itself at run time, the same
# arrangement www/chromium uses.
#
# Brave looks for it beside its own binary, in DIR_ASSETS/WidevineCdm -- see
# DIR_BUNDLED_WIDEVINE_CDM in chrome/common/chrome_paths.cc -- while
# foreign-cdm installs into share/chromium, so link the one to the other.  The
# module itself stays where that port put it and is never copied here.
#
# The -h is what keeps a second run of this target inside the stage directory:
# without it ln follows the link left by the first run and writes another one
# into foreign-cdm's own directory.
WIDEVINE_RUN_DEPENDS=	foreign-cdm>0:www/foreign-cdm
WIDEVINE_VARS=		GN_ARGS+=enable_widevine=true
WIDEVINE_VARS_OFF=	GN_ARGS+=enable_widevine=false

post-install-WIDEVINE-on:
	${LN} -sfh ${LOCALBASE}/share/chromium/WidevineCdm \
		${STAGEDIR}${DATADIR}/WidevineCdm

post-install-QT6-on:
	${INSTALL_LIB} ${BUILD_WRKSRC}/out/${BUILDTYPE}/libqt6_shim.so \
		${STAGEDIR}${DATADIR}

SUB_FILES=	brave brave-browser.desktop pkg-message
SUB_LIST=	COMMENT="${COMMENT}"

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

LLVM_DEFAULT=	22
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
BINARY_ALIAS+=	ar=${LOCALBASE}/bin/llvm-ar${LLVM_DEFAULT} \
		c++=${LOCALBASE}/bin/clang++${LLVM_DEFAULT} \
		cc=${LOCALBASE}/bin/clang${LLVM_DEFAULT} \
		cpp=${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT} \
		ld=${LOCALBASE}/bin/ld.lld${LLVM_DEFAULT} \
		nm=${LOCALBASE}/bin/llvm-nm${LLVM_DEFAULT}

.if ${ARCH} == aarch64
GN_CPU=			arm64
RUST_ABI_TARGET=	aarch64-unknown-freebsd
FFMPEG_TARGET=		arm64
# swiftshader/lib/{libEGL.so,libGLESv2.so} is x86 only
PLIST_SUB+=		NOT_AARCH64="@comment "
.else
BUILD_DEPENDS+=		nasm:devel/nasm
GN_CPU=			x64
RUST_ABI_TARGET=	x86_64-unknown-freebsd
FFMPEG_TARGET=		x64
PLIST_SUB+=		NOT_AARCH64=""
.endif

FFMPEG_BDIR=	${BUILD_WRKSRC}/third_party/ffmpeg/build.${FFMPEG_TARGET}.freebsd/${FFMPEG_BRAND}
FFMPEG_CDIR=	${BUILD_WRKSRC}/third_party/ffmpeg/chromium/config/${FFMPEG_BRAND}/freebsd/${FFMPEG_TARGET}

# The config FFmpeg's configure writes, and which the GN build then reads out
# of FFMPEG_CDIR.  config.asm and config_components.asm come from the x86
# assembler path only: on arm64 configure never writes them, and the generated
# source list uses the .S files under libavcodec/aarch64 instead, which need no
# nasm config.  Upstream's own checked-in configs match, see
# third_party/ffmpeg/chromium/config/*/linux/arm64.
FFMPEG_CONFIGS=	config.h config_components.h \
		libavcodec libavformat libavutil
.if ${ARCH} != aarch64
FFMPEG_CONFIGS+=	config.asm config_components.asm
.endif

# brave-core patches 40 of Chromium's python build scripts to end in an import
# of brave_chromium_utils, which is how it hooks chromium_src/ overrides into
# them.  That module lives in //brave/script and is only importable because
# Brave's build driver puts it on PYTHONPATH; driving ninja directly, as this
# port does, leaves the first such script failing on ModuleNotFoundError.  The
# list is the one from src/brave/build/commands/lib/config.ts, without the
# three directories a gclient checkout has and this tree does not (they hold
# requests, cryptography and macholib, none of which a FreeBSD build reaches).
_PYTHONPATH=	${BUILD_WRKSRC}/brave/script:${BUILD_WRKSRC}/tools/grit/grit/extern:${BUILD_WRKSRC}/build:${BUILD_WRKSRC}/third_party/depot_tools

# Node sizes its default heap from the memory it sees (libuv takes the datasize
# limit for that where it is set), which has left the webpack bundles of the
# WebUIs, ai_chat_ui above all, with about 512 MB on aarch64 machines that have
# 16 GB, and they die of "JavaScript heap out of memory".  Brave's node_action
# passes the environment through, so a fixed limit here reaches every bundle.
NODE_HEAP_MB?=	4096

MAKE_ENV+=	C_INCLUDE_PATH=${LOCALBASE}/include \
		CPLUS_INCLUDE_PATH=${LOCALBASE}/include \
		GOCACHE=${WRKDIR}/go-cache \
		NODE_OPTIONS=--max-old-space-size=${NODE_HEAP_MB} \
		PYTHONPATH=${_PYTHONPATH} \
		PYTHONUNBUFFERED=1 \
		RUSTC_BOOTSTRAP=1
CONFIGURE_ENV+=	${MAKE_ENV}

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "To build ${PORTNAME}, you should have at least:"
	@${ECHO_MSG} "- ${WANTMEM} of memory"
	@${ECHO_MSG} "- ${WANTSPACE} of free disk space"
	@${ECHO_MSG}
	@${ECHO_MSG} "This build will use ${MAKE_JOBS_NUMBER} parallel job(s)."
	@${ECHO_MSG} "Linking takes over a gigabyte per job, so on a machine with"
	@${ECHO_MSG} "more cores than memory set MAKE_JOBS_NUMBER_LIMIT in"
	@${ECHO_MSG} "/etc/make.conf rather than letting every core link at once."
	@${ECHO_MSG}

# The official Chromium tarball is unpacked next to brave-core, which gclient
# would otherwise check out as src/brave.  ${FIND} is used instead of a glob so
# that the dotfiles in the Chromium root (.gn above all) are moved as well.
# brave-core carries its own patches for the Chromium tree and they are written
# against pristine Chromium, so they have to go in before the FreeBSD patches
# in files/, which the regular patch phase applies right after this target.
# The layout below patches/ mirrors the Chromium tree.
#
# Roughly fifty of them are for Android and iOS files that the release tarball
# does not ship.  None of brave-core's patches creates a file, so a patch whose
# target is missing is one for a platform this port does not build, and it is
# skipped; everything else has to apply.
pre-patch:
# Unpacked here and not in the extract phase, see EXTRACT_ONLY.  The Chromium
# tarball is moved next to brave-core, which gclient would otherwise
# check out as src/brave.  ${FIND} is used instead of a glob so that the
# dotfiles in the Chromium root (.gn above all) are moved as well.
	@if [ ! -f ${WRKSRC}/src/chrome/VERSION ]; then \
		${ECHO_MSG} "===>  Extracting ${_CHROMIUM_DIST}"; \
		${MKDIR} ${WRKSRC}/src && \
		${TAR} -xf ${_DISTDIR}/${_CHROMIUM_DIST} -C ${WRKDIR} && \
		cd ${WRKDIR}/chromium-${CHROME_VERSION} && ${FIND} . -mindepth 1 \
		    -maxdepth 1 -exec ${MV} {} ${WRKSRC}/src/ \; && \
		${RMDIR} ${WRKDIR}/chromium-${CHROME_VERSION}; \
	fi
# tsgo needs tsc/ only, and not its 50,000 test files.  The Go modules from
# the vendor tarball go beside tsc/go.mod: www/chromium relies on the tarball
# unpacking straight into the TypeScript checkout, so look for the vendor
# directory wherever it landed if it is not there.
	@if [ ! -f ${WRKSRC}/src/typescript/tsc/go.mod ]; then \
		${ECHO_MSG} "===>  Extracting tsc from ${_TS_DIST}"; \
		${TAR} -x -C ${WRKDIR} -f ${_DISTDIR}/${_TS_DIST} \
		    --exclude 'TypeScript-${TSV}/tsc/testdata' \
		    'TypeScript-${TSV}/tsc' && \
		${TAR} -x -C ${WRKDIR} -f ${_DISTDIR}/${_TS_VENDOR_DIST} && \
		${MKDIR} ${WRKSRC}/src/typescript && \
		${MV} ${WRKDIR}/TypeScript-${TSV}/tsc ${WRKSRC}/src/typescript/tsc; \
	fi
	@if [ ! -f ${WRKSRC}/src/typescript/tsc/vendor/modules.txt ]; then \
		_v=$$(${FIND} ${WRKDIR} -path ${WRKSRC} -prune -o \
		    -path '*/tsc/vendor/modules.txt' -print | ${HEAD} -1); \
		if [ -z "$${_v}" ]; then \
			${ECHO_MSG} "===>  No tsc/vendor in ${_TS_VENDOR_DIST}"; \
			${FALSE}; \
		fi; \
		${MV} $${_v%/modules.txt} ${WRKSRC}/src/typescript/tsc/vendor; \
	fi
.if ${PORT_OPTIONS:MNODEMODS}
# With NODEMODS the Node modules come from a distfile.  They belong to
# brave-core.
	@if [ ! -d ${WRKSRC}/src/brave/node_modules ]; then \
		${ECHO_MSG} "===>  Extracting ${NODE_MODULES_DIST}"; \
		${TAR} -xf ${_DISTDIR}/${NODE_MODULES_DIST} -C ${WRKSRC}/src/brave; \
	fi
.endif
	@${ECHO_MSG} "===>  Applying brave-core patches to the Chromium tree"
	@cd ${WRKSRC}/src/brave/patches && ${FIND} . -name '*.patch' | sort | \
	while read _p; do \
		_d=$$(dirname "$${_p}"); \
		_f=$$(${AWK} '/^\+\+\+ b\//{sub(/^\+\+\+ b\//, ""); \
		    sub(/\t.*/, ""); print; exit}' "$${_p}"); \
		[ -f "${WRKSRC}/src/$${_d}/$${_f}" ] || continue; \
		${PATCH} -s -t -d ${WRKSRC}/src/$${_d} -p1 \
		    -i ${WRKSRC}/src/brave/patches/$${_p} || exit 1; \
	done

pre-configure:
# Chromium picks the Rust standard library out of the sysroot by crate
# name, and where a crate is present more than once it takes whichever
# sorts first.  Two toolchains installed side by side therefore end up
# mixing rlibs from different builds, and since Rust puts a per-build hash
# into every symbol name, the link fails much later on undefined core
# symbols.  Say so now instead.
	@_dup=$$(${LS} ${LOCALBASE}/lib/rustlib/${RUST_ABI_TARGET}/lib/*.rlib \
	    2>/dev/null | ${SED} -e 's|.*/lib||' -e 's|-[0-9a-f]*\.rlib$$||' \
	    | ${SORT} | uniq -d | ${TR} '\n' ' '); \
	if [ -n "$${_dup}" ]; then \
		${ECHO_MSG} "===>  More than one rlib per crate in ${LOCALBASE}/lib/rustlib/${RUST_ABI_TARGET}/lib:"; \
		${ECHO_MSG} "      $${_dup}"; \
		${ECHO_MSG} "      Usually these are leftovers from an earlier Rust,"; \
		${ECHO_MSG} "      owned by no package.  Compare the directory against"; \
		${ECHO_MSG} "      pkg info -ql rust and delete what is not listed."; \
		${FALSE}; \
	fi
	cd ${BUILD_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		./build/linux/unbundle/replace_gn_files.py --system-libraries \
		dav1d flac fontconfig harfbuzz libdrm libpng \
		libusb libwebp libxml libxslt openh264 opus || ${FALSE}
# Chromium ships an unreleased FFmpeg, so its config has to be generated
	cd ${BUILD_WRKSRC}/media/ffmpeg && \
		${PYTHON_CMD} scripts/build_ffmpeg.py freebsd ${FFMPEG_TARGET} \
		--config-only --branding=${FFMPEG_BRAND}
	cd ${FFMPEG_BDIR} && ${GMAKE} ffversion.h
	@for _e in ${FFMPEG_CONFIGS}; do \
		if [ -e ${FFMPEG_BDIR}/$${_e} ]; then continue; fi; \
		${ECHO_MSG} "===>  FFmpeg produced no $${_e} in ${FFMPEG_BDIR}"; \
		${ECHO_MSG} "      The build needs ${FFMPEG_CDIR}/$${_e}."; \
		${FALSE}; \
	done
	${MKDIR} ${FFMPEG_CDIR}
.for _e in ${FFMPEG_CONFIGS}
	${CP} -pR ${FFMPEG_BDIR}/${_e} ${FFMPEG_CDIR}
.endfor
	@${REINPLACE_CMD} -e 's|$${LOCALBASE}|${LOCALBASE}|;s|$${MODCLANG_VERSION}|${LLVM_DEFAULT}|' \
		${BUILD_WRKSRC}/build/linux/strip_binary.gni \
		${BUILD_WRKSRC}/build/rust/rust_bindgen.gni \
		${BUILD_WRKSRC}/build/rust/rust_bindgen_generator.gni
# Chromium's own change to the TypeScript library files, see
# third_party/typescript/README.chromium.  The CIPD package has it applied
# already; the tsgo built from source in pre-build has to get it here.
	${PATCH} -d ${BUILD_WRKSRC}/typescript/tsc/internal/bundled/libs -Ep2 < \
		${BUILD_WRKSRC}/third_party/typescript/linux-amd64/3pp/patches/typescript_native_preview.patch

	${CP} ${BUILD_WRKSRC}/chrome/VERSION ${BUILD_WRKSRC}/chrome/VERSION.chromium
	@${REINPLACE_CMD} -e 's|^MINOR=.*|MINOR=${BRAVE_VERSION_MAJOR}|' \
		-e 's|^BUILD=.*|BUILD=${BRAVE_VERSION_MINOR}|' \
		-e 's|^PATCH=.*|PATCH=${BRAVE_VERSION_BUILD}|' \
		${BUILD_WRKSRC}/chrome/VERSION
	cd ${WRKSRC}/src/brave && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		build/util/version.py gen ../chrome/VERSION

	@if [ ! -f ${_LEO}/tokens/skia/nala_color_id.h ]; then \
		${_PNPM_INSTALL}; \
	fi

	@if [ ! -f ${_LEO}/tokens/skia/nala_color_id.h ]; then \
		${ECHO_MSG} "===>  @brave/leo has not been built: no ${_LEO}/tokens/skia/nala_color_id.h"; \
		${ECHO_MSG} "      Run 'corepack pnpm rebuild @brave/leo' in ${WRKSRC}/src/brave,"; \
		${ECHO_MSG} "      or delete that node_modules and ${WRKDIR}/pnpm and install again."; \
		${FALSE}; \
	fi

	cd ${BUILD_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/node \
		${FILESDIR}/update-branding.mjs \
		${WRKSRC}/src/brave/build/commands

	@${MKDIR} ${BUILD_WRKSRC}/.cargo
	@${ECHO_CMD} "[source.crates-io]" > ${BUILD_WRKSRC}/.cargo/config.toml
	@${ECHO_CMD} "replace-with = 'brave-wasm'" >> ${BUILD_WRKSRC}/.cargo/config.toml
	@${ECHO_CMD} "" >> ${BUILD_WRKSRC}/.cargo/config.toml
	@${ECHO_CMD} "[source.brave-wasm]" >> ${BUILD_WRKSRC}/.cargo/config.toml
	@${ECHO_CMD} "directory = '${BUILD_WRKSRC}/brave/third_party/wasm/vendor'" >> ${BUILD_WRKSRC}/.cargo/config.toml

pre-build:
# tsgo for devtools-frontend, in place of the Linux binary from CIPD.  The
# library files next to it are the ones from the CIPD package in the tarball.
	cd ${BUILD_WRKSRC}/typescript/tsc && \
		${SETENV} ${MAKE_ENV} go build -v -p ${MAKE_JOBS_NUMBER} -mod=vendor ./cmd/tsgo && \
		${LN} -sf ${BUILD_WRKSRC}/typescript/tsc/tsgo \
		${BUILD_WRKSRC}/third_party/typescript/linux-amd64/src/lib/tsc

do-configure:
	(cd ${WRKSRC}/src/esbuild && \
		${LOCALBASE}/bin/node scripts/esbuild.js \
		${LOCALBASE}/bin/esbuild --neutral && \
		${RM} -r ${BUILD_WRKSRC}/third_party/devtools-frontend/src/node_modules/esbuild && \
		${LN} -sf ${WRKSRC}/src/esbuild/npm/esbuild \
		${BUILD_WRKSRC}/third_party/devtools-frontend/src/node_modules/esbuild)
	${LN} -sf ${LOCALBASE}/bin/esbuild \
		${BUILD_WRKSRC}/third_party/devtools-frontend/src/third_party/esbuild/esbuild

# gn itself is built from the Chromium tree, no prebuilt binary is fetched
	cd ${BUILD_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} CC=${CC} CXX=${CXX} \
		LD=${CXX} READELF=${READELF} AR=${AR} NM=${NM} ${PYTHON_CMD} \
		./tools/gn/bootstrap/bootstrap.py -j${MAKE_JOBS_NUMBER} \
		${GN_BOOTSTRAP_FLAGS}

# Dependencies Chromium normally expects below third_party/
	@${MKDIR} ${BUILD_WRKSRC}/third_party/node/freebsd/node-freebsd/bin
	${LN} -sf ${LOCALBASE}/bin/node \
		${BUILD_WRKSRC}/third_party/node/freebsd/node-freebsd/bin/node
# Brave builds its wasm crates with cargo, out of this directory and with
# it first in PATH, so both binaries have to be here.
	@${MKDIR} ${BUILD_WRKSRC}/third_party/rust-toolchain/bin
	${LN} -sf ${LOCALBASE}/bin/rustc \
		${BUILD_WRKSRC}/third_party/rust-toolchain/bin/rustc
	${LN} -sf ${LOCALBASE}/bin/cargo \
		${BUILD_WRKSRC}/third_party/rust-toolchain/bin/cargo
	${LN} -sf ${LOCALBASE}/bin/gperf \
		${BUILD_WRKSRC}/third_party/gperf/cipd/bin/gperf
	@${MKDIR} ${BUILD_WRKSRC}/buildtools/freebsd
	${LN} -sf ${BUILD_WRKSRC}/buildtools/linux64/clang-format \
		${BUILD_WRKSRC}/buildtools/freebsd
	${LN} -sf ${GN} ${BUILD_WRKSRC}/buildtools/freebsd
	${LN} -sf /usr/bin/strip ${BUILD_WRKSRC}/buildtools/freebsd/strip

# chromium_src/ overrides only take effect through redirect_cc
	${CC} ${CFLAGS} -o ${REDIRECT_CC} ${FILESDIR}/redirect_cc.c

	cd ${BUILD_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GN} gen \
		--args='${GN_ARGS}' out/${BUILDTYPE}

# Builds the NODEMODS distfile.  It has to be made from a finished install and
# not from the lockfile alone: @brave/leo runs its own npm install and then
# generates the Skia colour ids and the icon headers the browser is compiled
# against, so only a complete node_modules is usable offline.  Run this with
# NODEMODS off (the modules are installed by pre-configure), then upload the
# tarball to NODE_MODULES_SITE and run "make makesum" with NODEMODS on.
gen-node-modules: patch
	@if [ ! -f ${_LEO}/tokens/skia/nala_color_id.h ]; then \
		${_PNPM_INSTALL}; \
	fi
	@if [ ! -f ${_LEO}/tokens/skia/nala_color_id.h ]; then \
		${ECHO_MSG} "===>  @brave/leo has not been built, refusing to pack"; \
		${ECHO_MSG} "      an incomplete ${NODE_MODULES_DIST}."; \
		${FALSE}; \
	fi
	@${ECHO_MSG} "===>  Packing ${NODE_MODULES_DIST}"
	@cd ${WRKSRC}/src/brave && ${TAR} -c -J -f ${WRKDIR}/${NODE_MODULES_DIST} \
		node_modules
	@${ECHO_MSG} "===>  ${WRKDIR}/${NODE_MODULES_DIST}"

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/out/${BUILDTYPE}/brave \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/out/${BUILDTYPE}/*.pak ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/out/${BUILDTYPE}/*.bin ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/out/${BUILDTYPE}/icudtl.dat ${STAGEDIR}${DATADIR}
	cd ${BUILD_WRKSRC}/out/${BUILDTYPE} && \
		${COPYTREE_SHARE} "locales resources" ${STAGEDIR}${DATADIR}
.for _f in libEGL.so libGLESv2.so libVkICD_mock_icd.so
	${INSTALL_LIB} ${BUILD_WRKSRC}/out/${BUILDTYPE}/${_f} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_LIB} ${BUILD_WRKSRC}/out/${BUILDTYPE}/libvulkan.so.1 \
		${STAGEDIR}${DATADIR}/libvulkan.so
.if ${ARCH} != aarch64
	${INSTALL_LIB} ${BUILD_WRKSRC}/out/${BUILDTYPE}/libvk_swiftshader.so \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/out/${BUILDTYPE}/vk_swiftshader_icd.json \
		${STAGEDIR}${DATADIR}
.endif
.for _s in 24 48 64 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${_s}x${_s}/apps
	${INSTALL_DATA} \
		${WRKSRC}/src/brave/app/theme/brave/product_logo_${_s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${_s}x${_s}/apps/brave.png
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/brave ${STAGEDIR}${PREFIX}/bin/brave
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKDIR}/brave-browser.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.post.mk>
