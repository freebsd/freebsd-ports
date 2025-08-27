PORTNAME=	ringrtc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.56.0
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
		LOCAL/mikael/ringrtc/:opus \
		LOCAL/mikael/ringrtc/:perfetto \
		LOCAL/mikael/ringrtc/:protobufjs \
		LOCAL/mikael/ringrtc/:re2 \
		LOCAL/mikael/ringrtc/:testing \
		LOCAL/mikael/ringrtc/:third_party \
		LOCAL/mikael/ringrtc/:tools
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

ONLY_FOR_ARCHS=	aarch64 amd64

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
WEBRTC_REV=	7204a

# modify webrtc_fetch.sh, then sh webrtc_fetch.sh
BASE_REV=		4ba67f727a84a10e32a417dc7e194f4fc6a23390
BORINGSSL_REV=		9295969e1dad2c31d0d99481734c1c68dcbc6403
BUILD_REV=		7adbc7e3263f3ab427ba7c5ac7839a69082ff7fb
BUILDTOOLS_REV=		1fc7350e65e9d7848c083b83aaf67611e74a5654
CATAPULT_REV=		5477c6dfde1132b685c73edc16e1bc71449a691d
ICU_REV=		b929596baebf0ab4ac7ec07f38365db4c50a559d
LIBCUBEB_VER=		0.27.0
LIBJPEG_TURBO_REV=	e14cbfaa85529d47f9f55b0f104a579c1061f9ad
LIBSRTP_REV=		a52756acb1c5e133089c798736dd171567df11f5
LIBVPX_REV=		b84ca9b63730e7d4563573a56a66317eb0087ebf
LIBYUV_REV=		61bdaee13a701d2b52c6dc943ccc5c888077a591
NASM_REV=		9f916e90e6fc34ec302573f6ce147e43e33d68ca
OPUS_REV=		55513e81d8f606bd75d0ff773d2144e5f2a732f5
PERFETTO_REV=		dd35b295cd359ba094404218414955f961a0d6ae
PROTOBUFJS_REV=		28bf5df73ef2f345a936d9cc95d64ba8ed426a53
RE2_REV=		c84a140c93352cdabbfb547c531be34515b12228
TESTING_REV=		44b0a8d794b28dbd74614e5f5e7da2b407030647
THIRD_PARTY_REV=	8a150db896356cd9b47f8c1a6d916347393f90f2
TOOLS_REV=		901b847deda65d44f1bba16a9f47e2ea68a805be

BINARY_ALIAS=	vpython3=${PYTHON_CMD}

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
		extra_ldflags="${LDFLAGS}"

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
