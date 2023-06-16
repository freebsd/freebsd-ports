PORTNAME=	ringrtc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.28.0
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

USES=		cargo gnome localbase:ldflags ninja pkgconfig python:3.7+,build \
		tar:xz
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
GH_TUPLE=	signalapp:ringrtc:${DISTVERSIONPREFIX}${DISTVERSION} \
		signalapp:webrtc:${WEBRTC_REV}:webrtc

# sh net-im/signal-desktop/get_deps.sh
WEBRTC_REV=	5615a

# modify webrtc_fetch.sh, then sh webrtc_fetch.sh
BASE_REV=		0fc91d5d9071a1619d481fbc6a166fcd9a4ac0a9
BORINGSSL_REV=		ca1690e221677cea3fb946f324eb89d846ec53f2
BUILD_REV=		07283ef796b29a02df30fbdb498b978f31d00410
BUILDTOOLS_REV=		d110f6238fee0e4c82ab64606e5e967a3c809c55
CATAPULT_REV=		a22c2597b5bfa481324838866945c3ed7394ac47
ICU_REV=		c6b68522318204f795a8f04caebf6c0beb679cc4
LIBJPEG_TURBO_REV=	0b6e6a152242c2fa30ffb29633d1b7d7b229b46b
LIBSRTP_REV=		5b7c744eb8310250ccc534f3f86a2015b3887a0a
LIBVPX_REV=		db69ce6aea278bee88668fd9cc2af2e544516fdb
LIBYUV_REV=		2bdc210be9eb11ded16bf3ef1f6cadb0d4dcb0c2
NASM_REV=		7fc833e889d1afda72c06220e5bed8fb43b2e5ce
TESTING_REV=		b93e19cb405e9c39c414470ce1bca7e17aaae347
THIRD_PARTY_REV=	82835c7ebd240b08997ee36a42eae06b9e386b95
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

# fetch -qo - https://raw.githubusercontent.com/signalapp/ringrtc/v2.28.0/src/rust/Cargo.lock | awk -f /usr/ports/Mk/Scripts/cargo-crates.awk | portedit merge -i Makefile
CARGO_CRATES=	adler-1.0.2 \
		aead-0.4.3 \
		aes-0.7.5 \
		aes-gcm-siv-0.10.3 \
		aho-corasick-1.0.1 \
		android_system_properties-0.1.5 \
		anyhow-1.0.71 \
		autocfg-1.1.0 \
		base64-0.13.1 \
		bincode-1.3.3 \
		bitflags-1.3.2 \
		block-buffer-0.9.0 \
		bumpalo-3.12.1 \
		byteorder-1.4.3 \
		bytes-1.4.0 \
		cc-1.0.79 \
		cesu8-1.1.0 \
		cfg-if-1.0.0 \
		chrono-0.4.24 \
		cipher-0.3.0 \
		combine-4.6.6 \
		core-foundation-sys-0.8.4 \
		cpufeatures-0.2.7 \
		crc32fast-1.3.2 \
		crypto-mac-0.11.1 \
		ctr-0.8.0 \
		darling-0.20.1 \
		darling_core-0.20.1 \
		darling_macro-0.20.1 \
		digest-0.9.0 \
		displaydoc-0.2.4 \
		either-1.8.1 \
		env_logger-0.10.0 \
		errno-0.3.1 \
		errno-dragonfly-0.1.2 \
		fastrand-1.9.0 \
		fixedbitset-0.4.2 \
		flate2-1.0.26 \
		fnv-1.0.7 \
		form_urlencoded-1.1.0 \
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
		ghash-0.4.4 \
		hashbrown-0.12.3 \
		heck-0.4.1 \
		hermit-abi-0.2.6 \
		hermit-abi-0.3.1 \
		hex-0.4.3 \
		hkdf-0.11.0 \
		hmac-0.11.0 \
		humantime-2.1.0 \
		iana-time-zone-0.1.56 \
		iana-time-zone-haiku-0.1.2 \
		ident_case-1.0.1 \
		idna-0.3.0 \
		indexmap-1.9.3 \
		instant-0.1.12 \
		io-lifetimes-1.0.10 \
		is-terminal-0.4.7 \
		itertools-0.10.5 \
		itoa-1.0.6 \
		jni-0.19.0 \
		jni-sys-0.3.0 \
		js-sys-0.3.61 \
		lazy_static-1.4.0 \
		libc-0.2.142 \
		libloading-0.6.7 \
		linux-raw-sys-0.3.7 \
		log-0.4.17 \
		memchr-2.5.0 \
		miniz_oxide-0.7.1 \
		multimap-0.8.3 \
		neon-0.10.1 \
		neon-build-0.10.1 \
		neon-macros-0.10.1 \
		neon-runtime-0.10.1 \
		ntapi-0.4.1 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		num_cpus-1.15.0 \
		num_enum-0.5.11 \
		num_enum_derive-0.5.11 \
		once_cell-1.17.1 \
		opaque-debug-0.3.0 \
		percent-encoding-2.2.0 \
		petgraph-0.6.3 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		polyval-0.5.3 \
		ppv-lite86-0.2.17 \
		prettyplease-0.1.25 \
		proc-macro-crate-1.3.1 \
		proc-macro2-1.0.56 \
		prost-0.11.9 \
		prost-build-0.11.9 \
		prost-derive-0.11.9 \
		prost-types-0.11.9 \
		quote-1.0.26 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.3.5 \
		regex-1.8.1 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.29 \
		regex-syntax-0.7.1 \
		ring-0.16.20 \
		rustix-0.37.19 \
		rustls-0.20.8 \
		ryu-1.0.13 \
		same-file-1.0.6 \
		sct-0.7.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.162 \
		serde_derive-1.0.162 \
		serde_json-1.0.96 \
		serde_with-2.3.3 \
		serde_with_macros-2.3.3 \
		sha-1-0.9.8 \
		sha2-0.9.9 \
		slab-0.4.8 \
		smallvec-1.10.0 \
		spin-0.5.2 \
		static_assertions-1.1.0 \
		strsim-0.10.0 \
		subtle-2.4.1 \
		syn-1.0.109 \
		syn-2.0.15 \
		syn-mid-0.5.3 \
		sysinfo-0.28.4 \
		tempfile-3.5.0 \
		termcolor-1.2.0 \
		thiserror-1.0.40 \
		thiserror-impl-1.0.40 \
		time-0.3.21 \
		time-core-0.1.1 \
		time-macros-0.2.9 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		tokio-1.28.0 \
		toml_datetime-0.6.1 \
		toml_edit-0.19.8 \
		typenum-1.16.0 \
		unicode-bidi-0.3.13 \
		unicode-ident-1.0.8 \
		unicode-normalization-0.1.22 \
		universal-hash-0.4.1 \
		untrusted-0.7.1 \
		ureq-2.6.2 \
		url-2.3.1 \
		version_check-0.9.4 \
		walkdir-2.3.3 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.84 \
		wasm-bindgen-backend-0.2.84 \
		wasm-bindgen-macro-0.2.84 \
		wasm-bindgen-macro-support-0.2.84 \
		wasm-bindgen-shared-0.2.84 \
		web-sys-0.3.61 \
		webpki-0.22.0 \
		webpki-roots-0.22.6 \
		which-4.4.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-0.48.0 \
		windows-sys-0.45.0 \
		windows-sys-0.48.0 \
		windows-targets-0.42.2 \
		windows-targets-0.48.0 \
		windows_aarch64_gnullvm-0.42.2 \
		windows_aarch64_gnullvm-0.48.0 \
		windows_aarch64_msvc-0.42.2 \
		windows_aarch64_msvc-0.48.0 \
		windows_i686_gnu-0.42.2 \
		windows_i686_gnu-0.48.0 \
		windows_i686_msvc-0.42.2 \
		windows_i686_msvc-0.48.0 \
		windows_x86_64_gnu-0.42.2 \
		windows_x86_64_gnu-0.48.0 \
		windows_x86_64_gnullvm-0.42.2 \
		windows_x86_64_gnullvm-0.48.0 \
		windows_x86_64_msvc-0.42.2 \
		windows_x86_64_msvc-0.48.0 \
		winnow-0.4.6 \
		x25519-dalek-1.2.0 \
		zeroize-1.3.0 \
		zeroize_derive-1.4.2 \
		poksho,signal-crypto,zkcredential,zkgroup@git+https://github.com/signalapp/libsignal?tag=v0.23.1\#6f67aa5e4520f9d56f3f60794174db6285bf95e4 \
		curve25519-dalek@git+https://github.com/signalapp/curve25519-dalek?branch=lizard2\#4f0aa6653c51598daa0a2f53b8ba54ce0eedfbdd

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
