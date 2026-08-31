PORTNAME=	ringrtc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.70.2
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/mikael/ringrtc/:boringssl \
		LOCAL/mikael/ringrtc/:build \
		LOCAL/mikael/ringrtc/:buildtools \
		LOCAL/mikael/ringrtc/:catapult \
		LOCAL/mikael/ringrtc/:icu \
		LOCAL/mikael/ringrtc/:nasm \
		LOCAL/mikael/ringrtc/:libjpeg_turbo \
		LOCAL/mikael/ringrtc/:libsrtp \
		LOCAL/mikael/ringrtc/:libvpx \
		LOCAL/mikael/ringrtc/:libyuv \
		LOCAL/mikael/ringrtc/:opus \
		LOCAL/mikael/ringrtc/:perfetto \
		LOCAL/mikael/ringrtc/:protobufjs \
		LOCAL/mikael/ringrtc/:re2 \
		LOCAL/mikael/ringrtc/:testing \
		LOCAL/mikael/ringrtc/:third_party \
		LOCAL/mikael/ringrtc/:tools
DISTFILES=	boringssl-${BORINGSSL_REV}.tar.gz:boringssl \
		build-${BUILD_REV}.tar.gz:build \
		buildtools-${BUILDTOOLS_REV}.tar.gz:buildtools \
		catapult-${CATAPULT_REV}.tar.gz:catapult \
		icu-${ICU_REV}.tar.gz:icu \
		nasm-${NASM_REV}.tar.gz:nasm \
		libjpeg_turbo-${LIBJPEG_TURBO_REV}.tar.gz:libjpeg_turbo \
		libsrtp-${LIBSRTP_REV}.tar.gz:libsrtp \
		libvpx-${LIBVPX_REV}.tar.gz:libvpx \
		libyuv-${LIBYUV_REV}.tar.gz:libyuv \
		opus-${OPUS_REV}.tar.gz:opus \
		perfetto-${PERFETTO_REV}.tar.gz:perfetto \
		protobuf_javascript-${PROTOBUFJS_REV}.tar.gz:protobufjs \
		re2-${RE2_REV}.tar.gz:re2 \
		testing-${TESTING_REV}.tar.gz:testing \
		third_party-${THIRD_PARTY_REV}.tar.gz:third_party \
		tools-${TOOLS_REV}.tar.gz:tools

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Middleware library for Signal-Desktop
WWW=		https://github.com/signalapp/ringrtc

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	gn:devel/gn \
		protoc:devel/protobuf
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libpulse.so:audio/pulseaudio

USES=		cargo gnome jpeg localbase:ldflags ninja pkgconfig python:build \
		tar:xz
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
GH_TUPLE=	signalapp:ringrtc:${DISTVERSIONPREFIX}${DISTVERSION} \
		signalapp:webrtc:${WEBRTC_REV}:webrtc

# sh net-im/signal-desktop/get_deps.sh
WEBRTC_REV=	7871e

# modify webrtc_fetch.sh, then sh webrtc_fetch.sh
BORINGSSL_REV=		f91f1447397c6719f9774dfb8e67329378e1f3d3
BUILD_REV=		d296a9fec6186f2c109758c7d3f93cbef936dfc3
BUILDTOOLS_REV=		17495e454aae81b581e8b3caccbb53054509b280
CATAPULT_REV=		2852bb7e91e4995502ffb72b7ed21412ee157914
ICU_REV=		3859e64eed5d34544b27fbcab0ac1685ce83df3c
LIBCUBEB_VER=		0.36.0
LIBJPEG_TURBO_REV=	640f254ad0fa03f6b1f29f89b7dd9366f2f6e533
LIBSRTP_REV=		cd5d177bf1fde755ddb4c7f0d9ff7693f8b49e5e
LIBVPX_REV=		31af37b1bd2774d11a932c1cd9a3849328375f64
LIBYUV_REV=		de63bd90f4396313f864ad58b65279e7894451a9
NASM_REV=		525a09a813be0f75b646ee93fc2a31c27b87d722
OPUS_REV=		3da9f7a6db1c05c3996cb363a9d1931a978bf1be
PERFETTO_REV=		82ad4b69cbaf64e26c639061b1712756a9cc5e20
PROTOBUFJS_REV=		e6d763860001ba1a76a63adcff5efb12b1c96024
RE2_REV=		972a15cedd008d846f1a39b2e88ce48d7f166cbd
TESTING_REV=		5c19204b6395adfad25f83bbbd56439af9f86f7f
THIRD_PARTY_REV=	7c92732938de0ef7e28f5da231994723f938f407
TOOLS_REV=		8e4d26ef387bfa4c07e66dd1c7399c3d53ef1451

BINARY_ALIAS=	python3=${PYTHON_CMD} \
		vpython3=${PYTHON_CMD}

# Keep in sync with https://github.com/signalapp/ringrtc/blob/v2.53.0/bin/build-desktop#L130
# Run "gn args out/release --list" for all variables.
# Some parts don't have use_system_* flag, and can be turned on/off by using
# replace_gn_files.py script, some parts just turned on/off for target host
# OS "target_os == is_bsd", like libusb, libpci.
GN_ARGS+=	rtc_build_examples=false \
		rtc_build_tools=false \
		rtc_include_tests=false \
		rtc_enable_protobuf=false \
		rtc_use_x11=false \
		rtc_enable_sctp=false \
		rtc_libvpx_build_vp9=true \
		rtc_disable_metrics=true \
		rtc_disable_trace_events=true \
		clang_use_chrome_plugins=false \
		fatal_linker_warnings=false \
		is_clang=true \
		treat_warnings_as_errors=false \
		use_custom_libcxx=false \
		use_custom_libunwind=true \
		use_lld=true \
		use_llvm_libatomic=false \
		use_sysroot=false \
		use_system_freetype=false \
		use_system_harfbuzz=true \
		use_system_libjpeg=true \
		use_udev=false \
		extra_cxxflags="${CXXFLAGS}" \
		extra_ldflags="${LDFLAGS}" \
		use_thin_lto=true \
		thin_lto_enable_optimizations=true \
		is_debug=false

MAKE_ARGS=	-C out/${BUILDTYPE}

WEBRTCDIR=	${WRKDIR}/${PORTNAME}-${DISTVERSION}/src/webrtc/src

CARGO_BUILD_ARGS=	--package ringrtc --features electron
CARGO_INSTALL=		no

USE_LDCONFIG=	yes

MAKE_ENV+=	OUTPUT_DIR=${WEBRTCDIR}/out

PLIST_FILES=	lib/libringrtc.so

RUSTC_VERSION!= rustc -V 2>/dev/null || true
MAKE_ENV+=	RUSTC_BOOTSTRAP=1

GN_ARGS+=	enable_rust=true \
		rust_sysroot_absolute="${LOCALBASE}" \
		rustc_version="${RUSTC_VERSION}"

post-extract:
	${MKDIR} ${WRKDIR}/${PORTNAME}-${DISTVERSION}/src/webrtc
	${MV} ${WRKDIR}/webrtc-${WEBRTC_REV} ${WEBRTCDIR}
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
	${MV} ${WRKDIR}/perfetto ${WEBRTCDIR}/third_party
	${MV} ${WRKDIR}/protobuf_javascript ${WEBRTCDIR}/third_party/protobuf-javascript/src
	${MV} ${WRKDIR}/re2 ${WEBRTCDIR}/third_party/re2/src
	${MV} ${WRKDIR}/tools ${WEBRTCDIR}

post-patch:
	${REINPLACE_CMD} "s|LOCALBASE|${LOCALBASE}|" \
		${WEBRTCDIR}/build/toolchain/gcc_toolchain.gni \
		${WEBRTCDIR}/buildtools/third_party/libc++/BUILD.gn
	${RM} -r ${CARGO_VENDOR_DIR}/cubeb-sys-${LIBCUBEB_VER}/libcubeb/src/cubeb-pulse-rs

	${ECHO_CMD} "# Generated from 'DEPS'" > ${WEBRTCDIR}/build/config/gclient_args.gni
	${ECHO_CMD} 1591703586 > ${WEBRTCDIR}/build/util/LASTCHANGE.committime
	${ECHO_CMD} "qqchose " > ${WEBRTCDIR}/build/util/LASTCHANGE

pre-build:
	cd ${WEBRTCDIR} && \
		${SETENV} ${CONFIGURE_ENV} gn gen out/release --args='${GN_ARGS}'

# build webrtc first, ringrtc needs libwebrtc.a
	cd ${WEBRTCDIR} \
		&& ${MAKE_ENV} CC=ccache CXX=ccache ninja -C out/release

do-install:
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/release/libringrtc.so \
		${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
