PORTNAME=	ringrtc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.33.0
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/mikael/ringrtc/:base \
		LOCAL/mikael/ringrtc/:boringssl \
		LOCAL/mikael/ringrtc/:build \
		LOCAL/mikael/ringrtc/:buildtools \
		LOCAL/mikael/ringrtc/:catapult \
		LOCAL/mikael/ringrtc/:icu \
		LOCAL/mikael/ringrtc/:nasm \
		LOCAL/mikael/ringrtc/:libjpeg_turbo \
		LOCAL/mikael/ringrtc/:libsrtp \
		LOCAL/mikael/ringrtc/:libvpx \
		LOCAL/mikael/ringrtc/:libyuv \
		LOCAL/mikael/ringrtc/:third_party \
		LOCAL/mikael/ringrtc/:testing \
		LOCAL/mikael/ringrtc/:opus
DISTFILES=	base-${BASE_REV}.tar.gz:base \
		boringssl-${BORINGSSL_REV}.tar.gz:boringssl \
		build-${BUILD_REV}.tar.gz:build \
		buildtools-${BUILDTOOLS_REV}.tar.gz:buildtools \
		catapult-${CATAPULT_REV}.tar.gz:catapult \
		icu-${ICU_REV}.tar.gz:icu \
		nasm-${NASM_REV}.tar.gz:nasm \
		libjpeg_turbo-${LIBJPEG_TURBO_REV}.tar.gz:libjpeg_turbo \
		libsrtp-${LIBSRTP_REV}.tar.gz:libsrtp \
		libvpx-${LIBVPX_REV}.tar.gz:libvpx \
		libyuv-${LIBYUV_REV}.tar.gz:libyuv \
		third_party-${THIRD_PARTY_REV}.tar.gz:third_party \
		testing-${TESTING_REV}.tar.gz:testing \
		opus-${OPUS_REV}.tar.gz:opus

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Middleware library for Signal-Desktop
WWW=		https://github.com/signalapp/ringrtc

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/../../LICENSE

BUILD_DEPENDS=	gn:devel/gn \
		protoc:devel/protobuf
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfreetype.so:print/freetype2 \
		libpulse.so:audio/pulseaudio

USES=		cargo gnome localbase:ldflags ninja pkgconfig python:build \
		tar:xz
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
GH_TUPLE=	signalapp:ringrtc:${DISTVERSIONPREFIX}${DISTVERSION} \
		signalapp:webrtc:${WEBRTC_REV}:webrtc

# sh net-im/signal-desktop/get_deps.sh
WEBRTC_REV=	5845h

# modify webrtc_fetch.sh, then sh webrtc_fetch.sh
BASE_REV=		ca4474373784d15364b5d190970e5bdfa1544c2a
BORINGSSL_REV=		ae88f198a49d77993e9c44b017d0e69c810dc668
BUILD_REV=		6c0e0e0c84aa581f9bfa042e511dc9aaffa8fd82
BUILDTOOLS_REV=		3739a3619309af3b788379ad0936ca00b981616e
CATAPULT_REV=		89fad9023d62d7031789a904b2aa6bd1d4d0a3e2
ICU_REV=		e8c3bc9ea97d4423ad0515e5f1c064f486dae8b1
LIBJPEG_TURBO_REV=	aa4075f116e4312537d0d3e9dbd5e31096539f94
LIBSRTP_REV=		5b7c744eb8310250ccc534f3f86a2015b3887a0a
LIBVPX_REV=		278d0acd32c3fd544e6f99cbfd714df3430a6442
LIBYUV_REV=		552571e8b24b2619c39ec176e6cb8e75d3e7fdd3
NASM_REV=		7fc833e889d1afda72c06220e5bed8fb43b2e5ce
TESTING_REV=		f3b8f1d8c1d7ca49f9a77b8e669c357572f4447c
THIRD_PARTY_REV=	770155421d251b9541301084d0db46812540c251
OPUS_REV=		74d8597f47aa680c9f9e21ab0b99c8c0632fe27d

BINARY_ALIAS=	vpython3=${PYTHON_CMD}

# Keep in sync with https://github.com/signalapp/ringrtc/blob/${DISTVERSION}/bin/build-electron#L96
# Run "gn args out/Release --list" for all variables.
# Some parts don't have use_system_* flag, and can be turned on/off by using
# replace_gn_files.py script, some parts just turned on/off for target host
# OS "target_os == is_bsd", like libusb, libpci.
GN_ARGS+=	rtc_build_examples=false \
		rtc_build_tools=false \
		rtc_include_tests=false \
		rtc_enable_protobuf=false \
		rtc_use_x11=false \
		rtc_enable_sctp=false \
		rtc_libvpx_build_vp9=false \
		rtc_include_ilbc=false \
		use_custom_libcxx=false \
		is_debug=false \
		is_clang=true \
		clang_use_chrome_plugins=false \
		treat_warnings_as_errors=false \
		extra_cxxflags="${CXXFLAGS}" \
		extra_ldflags="${LDFLAGS}"

MAKE_ARGS=	-C out/${BUILDTYPE}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}/src/rust
WEBRTCDIR=	${WRKDIR}/${PORTNAME}-${DISTVERSION}/src/webrtc/src

# fetch -qo - https://raw.githubusercontent.com/signalapp/ringrtc/v2.31.2/src/rust/Cargo.lock | awk -f /usr/ports/Mk/Scripts/cargo-crates.awk | portedit merge -i Makefile
CARGO_CRATES=	addr2line-0.21.0 \
		adler-1.0.2 \
		aead-0.4.3 \
		aes-0.7.5 \
		aes-gcm-siv-0.10.3 \
		aho-corasick-1.0.5 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anstream-0.5.0 \
		anstyle-1.0.2 \
		anstyle-parse-0.2.1 \
		anstyle-query-1.0.0 \
		anstyle-wincon-2.1.0 \
		anyhow-1.0.75 \
		async-trait-0.1.73 \
		autocfg-1.1.0 \
		axum-0.6.20 \
		axum-core-0.3.4 \
		backtrace-0.3.69 \
		base64-0.13.1 \
		base64-0.21.3 \
		bincode-1.3.3 \
		bitflags-1.3.2 \
		bitflags-2.4.0 \
		block-buffer-0.9.0 \
		bumpalo-3.13.0 \
		byteorder-1.4.3 \
		bytes-1.4.0 \
		cc-1.0.83 \
		cesu8-1.1.0 \
		cfg-if-1.0.0 \
		chrono-0.4.28 \
		cipher-0.3.0 \
		clap-4.4.2 \
		clap_builder-4.4.2 \
		clap_derive-4.4.2 \
		clap_lex-0.5.1 \
		colorchoice-1.0.0 \
		combine-4.6.6 \
		core-foundation-sys-0.8.4 \
		cpufeatures-0.2.9 \
		crc32fast-1.3.2 \
		crypto-mac-0.11.1 \
		ctr-0.8.0 \
		darling-0.20.3 \
		darling_core-0.20.3 \
		darling_macro-0.20.3 \
		deranged-0.3.8 \
		digest-0.9.0 \
		displaydoc-0.2.4 \
		either-1.9.0 \
		env_logger-0.10.0 \
		equivalent-1.0.1 \
		errno-0.3.3 \
		errno-dragonfly-0.1.2 \
		fastrand-2.0.0 \
		fern-0.6.2 \
		fixedbitset-0.4.2 \
		flate2-1.0.27 \
		fnv-1.0.7 \
		form_urlencoded-1.2.0 \
		futures-0.3.28 \
		futures-channel-0.3.28 \
		futures-core-0.3.28 \
		futures-executor-0.3.28 \
		futures-io-0.3.28 \
		futures-macro-0.3.28 \
		futures-sink-0.3.28 \
		futures-task-0.3.28 \
		futures-util-0.3.28 \
		generic-array-0.14.7 \
		getrandom-0.1.16 \
		getrandom-0.2.10 \
		ghash-0.4.4 \
		gimli-0.28.0 \
		h2-0.3.21 \
		hashbrown-0.12.3 \
		hashbrown-0.14.0 \
		heck-0.4.1 \
		hermit-abi-0.3.2 \
		hex-0.4.3 \
		hkdf-0.11.0 \
		hmac-0.11.0 \
		http-0.2.9 \
		http-body-0.4.5 \
		httparse-1.8.0 \
		httpdate-1.0.3 \
		humantime-2.1.0 \
		hyper-0.14.27 \
		hyper-timeout-0.4.1 \
		iana-time-zone-0.1.57 \
		iana-time-zone-haiku-0.1.2 \
		ident_case-1.0.1 \
		idna-0.4.0 \
		indexmap-1.9.3 \
		indexmap-2.0.0 \
		is-terminal-0.4.9 \
		itertools-0.10.5 \
		itoa-1.0.9 \
		jni-0.19.0 \
		jni-sys-0.3.0 \
		js-sys-0.3.64 \
		lazy_static-1.4.0 \
		libc-0.2.147 \
		libloading-0.6.7 \
		linux-raw-sys-0.4.5 \
		log-0.4.20 \
		matchit-0.7.2 \
		memchr-2.6.2 \
		mime-0.3.17 \
		miniz_oxide-0.7.1 \
		mio-0.8.8 \
		multimap-0.8.3 \
		neon-0.10.1 \
		neon-build-0.10.1 \
		neon-macros-0.10.1 \
		neon-runtime-0.10.1 \
		ntapi-0.4.1 \
		num-traits-0.2.16 \
		num_cpus-1.16.0 \
		num_enum-0.7.0 \
		num_enum_derive-0.7.0 \
		object-0.32.0 \
		once_cell-1.18.0 \
		opaque-debug-0.3.0 \
		percent-encoding-2.3.0 \
		petgraph-0.6.4 \
		pin-project-1.1.3 \
		pin-project-internal-1.1.3 \
		pin-project-lite-0.2.13 \
		pin-utils-0.1.0 \
		polyval-0.5.3 \
		ppv-lite86-0.2.17 \
		prettyplease-0.1.25 \
		proc-macro-crate-1.3.1 \
		proc-macro2-1.0.66 \
		prost-0.11.9 \
		prost-build-0.11.9 \
		prost-derive-0.11.9 \
		prost-types-0.11.9 \
		quote-1.0.33 \
		rand-0.7.3 \
		rand-0.8.5 \
		rand_chacha-0.2.2 \
		rand_chacha-0.3.1 \
		rand_core-0.5.1 \
		rand_core-0.6.4 \
		rand_hc-0.2.0 \
		redox_syscall-0.3.5 \
		regex-1.9.4 \
		regex-automata-0.1.10 \
		regex-automata-0.3.7 \
		regex-syntax-0.6.29 \
		regex-syntax-0.7.5 \
		ring-0.16.20 \
		rustc-demangle-0.1.23 \
		rustix-0.38.10 \
		rustls-0.21.7 \
		rustls-webpki-0.100.2 \
		rustls-webpki-0.101.4 \
		rustversion-1.0.14 \
		ryu-1.0.15 \
		same-file-1.0.6 \
		sct-0.7.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.188 \
		serde_derive-1.0.188 \
		serde_json-1.0.105 \
		serde_with-2.3.3 \
		serde_with_macros-2.3.3 \
		sha-1-0.9.8 \
		sha2-0.9.9 \
		slab-0.4.9 \
		smallvec-1.11.0 \
		socket2-0.4.9 \
		socket2-0.5.3 \
		spin-0.5.2 \
		static_assertions-1.1.0 \
		strsim-0.10.0 \
		subtle-2.4.1 \
		syn-1.0.109 \
		syn-2.0.29 \
		syn-mid-0.5.4 \
		sync_wrapper-0.1.2 \
		sysinfo-0.29.10 \
		tempfile-3.8.0 \
		termcolor-1.2.0 \
		thiserror-1.0.47 \
		thiserror-impl-1.0.47 \
		time-0.1.45 \
		time-0.3.28 \
		time-core-0.1.1 \
		time-macros-0.2.14 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		tokio-1.32.0 \
		tokio-io-timeout-1.2.0 \
		tokio-macros-2.1.0 \
		tokio-stream-0.1.14 \
		tokio-util-0.7.8 \
		toml_datetime-0.6.3 \
		toml_edit-0.19.14 \
		tonic-0.9.2 \
		tonic-build-0.9.2 \
		tower-0.4.13 \
		tower-layer-0.3.2 \
		tower-service-0.3.2 \
		tracing-0.1.37 \
		tracing-attributes-0.1.26 \
		tracing-core-0.1.31 \
		try-lock-0.2.4 \
		typenum-1.16.0 \
		unicode-bidi-0.3.13 \
		unicode-ident-1.0.11 \
		unicode-normalization-0.1.22 \
		universal-hash-0.4.1 \
		untrusted-0.7.1 \
		ureq-2.7.1 \
		url-2.4.1 \
		utf8parse-0.2.1 \
		version_check-0.9.4 \
		walkdir-2.3.3 \
		want-0.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.87 \
		wasm-bindgen-backend-0.2.87 \
		wasm-bindgen-macro-0.2.87 \
		wasm-bindgen-macro-support-0.2.87 \
		wasm-bindgen-shared-0.2.87 \
		web-sys-0.3.64 \
		webpki-0.22.0 \
		webpki-roots-0.23.1 \
		which-4.4.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-0.48.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5 \
		winnow-0.5.15 \
		x25519-dalek-1.2.0 \
		zeroize-1.3.0 \
		zeroize_derive-1.4.2 \
		curve25519-dalek@git+https://github.com/signalapp/curve25519-dalek?branch=lizard2\#829f52e79c6d920243c8bf30c7f4ee2e8eac5246 \
		poksho,signal-crypto,zkcredential,zkgroup@git+https://github.com/signalapp/libsignal?tag=v0.23.1\#6f67aa5e4520f9d56f3f60794174db6285bf95e4

CARGO_BUILD_ARGS=	--features electron
CARGO_INSTALL=		no

USE_LDCONFIG=	yes

MAKE_ENV=	OUTPUT_DIR=${WEBRTCDIR}/out

PLIST_FILES=	lib/libringrtc.so

post-extract:
	${MKDIR} ${WRKDIR}/${PORTNAME}-${DISTVERSION}/src/webrtc
	${MV} ${WRKDIR}/webrtc-${WEBRTC_REV} ${WEBRTCDIR}
	${MV} ${WRKDIR}/base ${WEBRTCDIR}
	${MV} ${WRKDIR}/build ${WEBRTCDIR}
	${MV} ${WRKDIR}/buildtools ${WEBRTCDIR}
	${MV} ${WRKDIR}/testing ${WEBRTCDIR}
	${MV} ${WRKDIR}/third_party ${WEBRTCDIR}
	${MV} ${WRKDIR}/catapult ${WEBRTCDIR}/third_party
	${MV} ${WRKDIR}/boringssl ${WEBRTCDIR}/third_party/boringssl/src
	${MV} ${WRKDIR}/icu ${WEBRTCDIR}/third_party
	${MV} ${WRKDIR}/libjpeg_turbo ${WEBRTCDIR}/third_party
	${MV} ${WRKDIR}/libsrtp ${WEBRTCDIR}/third_party
	${MV} ${WRKDIR}/libvpx ${WEBRTCDIR}/third_party/libvpx/source
	${MV} ${WRKDIR}/libyuv ${WEBRTCDIR}/third_party
	${MV} ${WRKDIR}/nasm ${WEBRTCDIR}/third_party
	${MV} ${WRKDIR}/opus ${WEBRTCDIR}/ringrtc/opus/src

post-patch:
	${REINPLACE_CMD} "s|LOCALBASE|${LOCALBASE}|" \
		${WEBRTCDIR}/build/toolchain/gcc_toolchain.gni \
		${WEBRTCDIR}/buildtools/third_party/libc++/BUILD.gn

	${ECHO_CMD} "# Generated from 'DEPS'" > ${WEBRTCDIR}/build/config/gclient_args.gni
	${ECHO_CMD} 1591703586 > ${WEBRTCDIR}/build/util/LASTCHANGE.committime
	${ECHO_CMD} "qqchose " > ${WEBRTCDIR}/build/util/LASTCHANGE

pre-build:
	cd ${WEBRTCDIR} && \
		${SETENV} ${CONFIGURE_ENV} gn gen out/release --args='${GN_ARGS}'

# build webrtc first, ringrtc needs libwebrtc.a
	cd ${WEBRTCDIR} \
		&& ${MAKE_ENV} CC=ccache CXX=ccache ninja -C out/release

# it's not intended to be used outside of signal-desktop, put that in
# /usr/local/share/ringrtc instead?
do-install:
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/libringrtc.so \
		${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
