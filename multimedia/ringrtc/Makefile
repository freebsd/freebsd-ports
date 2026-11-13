PORTNAME=	ringrtc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.74.0
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

USES=		cargo gnome jpeg llvm:min=21,build localbase:ldflags ninja pkgconfig python:build \
		tar:xz
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
GH_TUPLE=	signalapp:ringrtc:${DISTVERSIONPREFIX}${DISTVERSION} \
		signalapp:webrtc:${WEBRTC_REV}:webrtc

# sh net-im/signal-desktop/get_deps.sh
WEBRTC_REV=	8037b

# modify webrtc_fetch.sh, then sh webrtc_fetch.sh
BORINGSSL_REV=		d9cace2c916914c437a10bf987017ba7792c0d57
BUILD_REV=		8a8d38839a9cfa81823701f32d67d66343d70876
BUILDTOOLS_REV=		4277578aa9c45906e51ad33cac1a5a7ad5288010
CATAPULT_REV=		1d18f6e11082de030c45fd55b556d15e3aa628a8
ICU_REV=		8cc91d9b6ab9991802fd208ee03a69714fd0251c
LIBCUBEB_VER=		0.38.0
LIBJPEG_TURBO_REV=	640f254ad0fa03f6b1f29f89b7dd9366f2f6e533
LIBSRTP_REV=		cd5d177bf1fde755ddb4c7f0d9ff7693f8b49e5e
LIBVPX_REV=		5ae5478f99abbe42101906d955458b3c98b587dd
LIBYUV_REV=		26e56be0f984af3dae4d0c0ab7a0bac8ac20e1b0
NASM_REV=		525a09a813be0f75b646ee93fc2a31c27b87d722
OPUS_REV=		212d66c20944d0a0db91132f826a27dd0d5edd5d
PERFETTO_REV=		de794788d545dcf05aacece46a7fb5385b52ac77
PROTOBUFJS_REV=		e6d763860001ba1a76a63adcff5efb12b1c96024
RE2_REV=		972a15cedd008d846f1a39b2e88ce48d7f166cbd
TESTING_REV=		b96dbc743d8b46742aed1bedf3e015eaeb9b2b09
THIRD_PARTY_REV=	8f1da83155caaa0d454042bffcbcdb7f1fcae844
TOOLS_REV=		b4235c8a2ce2b9daf74657dbd3b869d23235e87a

BINARY_ALIAS=	python3=${PYTHON_CMD} \
		vpython3=${PYTHON_CMD} \
		c++=${CXX} \
		cxx=${CXX} \
		cc=${CC}

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
		extra_cflags="${CFLAGS}" \
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
	${REINPLACE_CMD} "s|%%LLVM_PREFIX%%|${LLVM_PREFIX}|g" \
		${WEBRTCDIR}/build/toolchain/gcc_toolchain.gni
	${RM} -r ${CARGO_VENDOR_DIR}/cubeb-sys-${LIBCUBEB_VER}/libcubeb/src/cubeb-pulse-rs

	${ECHO_CMD} "# Generated from 'DEPS'" > ${WEBRTCDIR}/build/config/gclient_args.gni
	${ECHO_CMD} 1591703586 > ${WEBRTCDIR}/build/util/LASTCHANGE.committime
	${ECHO_CMD} "qqchose " > ${WEBRTCDIR}/build/util/LASTCHANGE

pre-build:
	cd ${WEBRTCDIR} && \
		${SETENV} ${CONFIGURE_ENV} gn gen out/release --args='${GN_ARGS}'

# after:
# https://github.com/signalapp/webrtc/commit/4d1a574afc3a286433ff14399dc5a4a2db6e6dc5
# https://github.com/signalapp/ringrtc/commit/6ce85e90017b224d07bdc190ce2871ceaf5fcb5a
# https://github.com/signalapp/webrtc/commit/37c2ad2fce0f776ce21714f71871befd0d349e63
# the api folder was removed but ringrtc/rffi/api is still in use in various place
# https://github.com/signalapp/webrtc/blob/8037a/rtc_base/logging.h#L72  

	${MKDIR} ${WEBRTCDIR}/ringrtc/rffi/api
	cd ${WRKSRC}/src/rust/src/webrtc_include && ${COPYTREE_SHARE} . ${WEBRTCDIR}/ringrtc/rffi/api
	
# build webrtc first, ringrtc needs libwebrtc.a
	cd ${WEBRTCDIR} \
		&& ${MAKE_ENV} CC=ccache CXX=ccache ninja -C out/release

do-install:
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/release/libringrtc.so \
		${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
