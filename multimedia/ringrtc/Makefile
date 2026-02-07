PORTNAME=	ringrtc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.61.0
PORTREVISION=	1
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
WEBRTC_REV=	7444a

# modify webrtc_fetch.sh, then sh webrtc_fetch.sh
BORINGSSL_REV=		db638238d29708a20b991af3b2488e45a8bbcf71
BUILD_REV=		045565e91c7360951bddbd0618a20ea59cdd31f3
BUILDTOOLS_REV=		3e6e75d1961a90054ee0e3030ee66b6a04164c10
CATAPULT_REV=		04c85a1d0e324464c6be4b3d193b47cb6177d03a
ICU_REV=		1b2e3e8a421efae36141a7b932b41e315b089af8
LIBCUBEB_VER=		0.33.0
LIBJPEG_TURBO_REV=	e14cbfaa85529d47f9f55b0f104a579c1061f9ad
LIBSRTP_REV=		a52756acb1c5e133089c798736dd171567df11f5
LIBVPX_REV=		8d00aca60b951444582b1373e4e47f0ca6e0871c
LIBYUV_REV=		5b22f31cb5d39c1309a589f148678c2a217e75db
NASM_REV=		e2c93c34982b286b27ce8b56dd7159e0b90869a2
OPUS_REV=		55513e81d8f606bd75d0ff773d2144e5f2a732f5
PERFETTO_REV=		d5bbee7afdf259af4212929ccbff467dd5349953
PROTOBUFJS_REV=		e6d763860001ba1a76a63adcff5efb12b1c96024
RE2_REV=		6569a9a3df256f4c0c3813cb8ee2f8eef6e2c1fb
TESTING_REV=		c030c132cbab406942fb208b7180f8846aa4abf1
THIRD_PARTY_REV=	de738129ebb915bbe34cdf06520c7050ef8aa9d9
TOOLS_REV=		3b73a00861c1cc1d6308e20786f42045b77864cd

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
