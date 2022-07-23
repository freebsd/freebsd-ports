PORTNAME=	ringrtc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.20.11
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
		LOCAL/mikael/ringrtc/:testing
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
		testing-${TESTING_REV}.tar.gz:testing

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Middleware library for Signal-Desktop

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

# Add extra-patch-no-mempcpy-nasm only when there's no mempcpy() in base.
# Nested variable expansion avoids executing the test when not needed for
# expanding EXTRA_PATCHES.
EXTRA_PATCHES+=	${"${:!${GREP} mempcpy ${CROSS_SYSROOT}/usr/include/string.h \
	|| ${TRUE}!}" == "":?${PATCHDIR}/extra-patch-no-mempcpy-nasm:}

# sh net-im/signal-desktop/get_deps.sh
WEBRTC_REV=	4896f

# modify webrtc_fetch.sh, then sh webrtc_fetch.sh
BASE_REV=	bee216d6736d6a471879c5fcd32c8aba863d4755
BORINGSSL_REV=	4d955d20d27bcf3ae71df091ad17d95229a7eb56
BUILD_REV=	b42b2033819f95b3e43f24e541938c671110966d
BUILDTOOLS_REV=	d8c375426d8f7f4147f7d4109bb63c12655fb8d6
CATAPULT_REV=	389f33bb40a3345b73a68613178c789476ceaecf
ICU_REV=	a9359a84a3969b3019db7d62899afb19642eefcd
LIBJPEG_TURBO_REV=	22f1a22c99e9dde8cd3c72ead333f425c5a7aa77
LIBSRTP_REV=	5b7c744eb8310250ccc534f3f86a2015b3887a0a
LIBVPX_REV=	df0d06de6d3b64e35b9e75ad72c571af061bc7b3
LIBYUV_REV=	3aebf69d668177e7ee6dbbe0025e5c3dbb525ff2
NASM_REV=	9215e8e1d0fe474ffd3e16c1a07a0f97089e6224
TESTING_REV=	c4769e51cb122096ea4cdc5ed6f7e57aa2315447
THIRD_PARTY_REV=	7835795588c74a353beb1e03b74d45fabfdf295f

BINARY_ALIAS=	python3=${PYTHON_CMD}

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
		extra_cxxflags="${CXXFLAGS}" \
		extra_ldflags="${LDFLAGS}"

MAKE_ARGS=	-C out/${BUILDTYPE}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}/src/rust
WEBRTCDIR=	${WRKDIR}/${PORTNAME}-${DISTVERSION}/src/webrtc/src

# fetch -qo - https://raw.githubusercontent.com/signalapp/ringrtc/v2.20.10/src/rust/Cargo.lock | awk -f /usr/ports/Mk/Scripts/cargo-crates.awk | portedit merge -i Makefile
CARGO_CRATES=	aes-0.7.5 \
		aho-corasick-0.7.18 \
		anyhow-1.0.53 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		base64-0.13.0 \
		bitflags-1.3.2 \
		block-buffer-0.9.0 \
		bumpalo-3.9.1 \
		byteorder-1.4.3 \
		bytes-1.1.0 \
		cc-1.0.72 \
		cesu8-1.1.0 \
		cfg-if-1.0.0 \
		chunked_transfer-1.4.0 \
		cipher-0.3.0 \
		combine-4.6.3 \
		cpufeatures-0.2.1 \
		crypto-mac-0.11.1 \
		cslice-0.2.0 \
		ctr-0.8.0 \
		curve25519-dalek-3.2.0 \
		digest-0.9.0 \
		either-1.6.1 \
		env_logger-0.8.4 \
		fastrand-1.7.0 \
		fixedbitset-0.2.0 \
		form_urlencoded-1.0.1 \
		futures-0.3.21 \
		futures-channel-0.3.21 \
		futures-core-0.3.21 \
		futures-executor-0.3.21 \
		futures-io-0.3.21 \
		futures-macro-0.3.21 \
		futures-sink-0.3.21 \
		futures-task-0.3.21 \
		futures-util-0.3.21 \
		generic-array-0.14.5 \
		getrandom-0.1.16 \
		hashbrown-0.11.2 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		hex-0.4.3 \
		hkdf-0.11.0 \
		hmac-0.11.0 \
		humantime-2.1.0 \
		idna-0.2.3 \
		indexmap-1.8.0 \
		instant-0.1.12 \
		itertools-0.10.3 \
		itoa-1.0.1 \
		jni-0.19.0 \
		jni-sys-0.3.0 \
		js-sys-0.3.56 \
		lazy_static-1.4.0 \
		libc-0.2.117 \
		libloading-0.6.7 \
		log-0.4.14 \
		matches-0.1.9 \
		memchr-2.4.1 \
		multimap-0.8.3 \
		neon-0.9.1 \
		neon-build-0.9.1 \
		neon-macros-0.9.1 \
		neon-runtime-0.9.1 \
		num_cpus-1.13.1 \
		num_enum-0.5.6 \
		num_enum_derive-0.5.6 \
		once_cell-1.9.0 \
		opaque-debug-0.3.0 \
		percent-encoding-2.1.0 \
		petgraph-0.5.1 \
		pin-project-lite-0.2.8 \
		pin-utils-0.1.0 \
		ppv-lite86-0.2.16 \
		proc-macro-crate-1.1.0 \
		proc-macro2-1.0.36 \
		prost-0.8.0 \
		prost-build-0.8.0 \
		prost-derive-0.8.0 \
		prost-types-0.8.0 \
		quote-1.0.15 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.2.10 \
		regex-1.5.5 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		ring-0.16.20 \
		rustls-0.19.1 \
		ryu-1.0.9 \
		same-file-1.0.6 \
		sct-0.6.1 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		serde_json-1.0.78 \
		sha2-0.9.9 \
		slab-0.4.5 \
		smallvec-1.8.0 \
		spin-0.5.2 \
		static_assertions-1.1.0 \
		subtle-2.4.1 \
		syn-1.0.86 \
		synstructure-0.12.6 \
		tempfile-3.3.0 \
		termcolor-1.1.2 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		tokio-1.16.1 \
		toml-0.5.8 \
		typenum-1.15.0 \
		unicode-bidi-0.3.7 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.9.0 \
		unicode-xid-0.2.2 \
		untrusted-0.7.1 \
		ureq-2.2.0 \
		url-2.2.2 \
		version_check-0.9.4 \
		walkdir-2.3.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.79 \
		wasm-bindgen-backend-0.2.79 \
		wasm-bindgen-macro-0.2.79 \
		wasm-bindgen-macro-support-0.2.79 \
		wasm-bindgen-shared-0.2.79 \
		web-sys-0.3.56 \
		webpki-0.21.4 \
		webpki-roots-0.21.1 \
		which-4.2.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		x25519-dalek-1.2.0 \
		zeroize-1.3.0 \
		zeroize_derive-1.3.2

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
