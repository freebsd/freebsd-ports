PORTNAME=	ringrtc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.51.0
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
WEBRTC_REV=	6998b

# modify webrtc_fetch.sh, then sh webrtc_fetch.sh
BASE_REV=		e0914b7606a151a3a12e994c400519f2e291c53f
BORINGSSL_REV=		d4b6eb542d4fd109baacd550935efd00c521e674
BUILD_REV=		64e296c42a93fbd27acc9a94713e4289273409b2
BUILDTOOLS_REV=		a660247d3c14a172b74b8e832ba1066b30183c97
CATAPULT_REV=		b15611f18b506cf9dbc03e9bf87dbc8df549ccce
ICU_REV=		bbccc2f6efc1b825de5f2c903c48be685cd0cf22
LIBCUBEB_VER=		0.27.0
LIBJPEG_TURBO_REV=	927aabfcd26897abb9776ecf2a6c38ea5bb52ab6
LIBSRTP_REV=		a52756acb1c5e133089c798736dd171567df11f5
LIBVPX_REV=		7a65480684b1b28bb9defae164bf0dc78b32653e
LIBYUV_REV=		10592b60c0b2c33210b7752454253dc2625b4305
NASM_REV=		f477acb1049f5e043904b87b825c5915084a9a29
OPUS_REV=		0e30966b198ad28943799eaf5b3b08100b6f70c3
PERFETTO_REV=		a0c2bc7919f7467cf4a8287c8389c3f96a3fcbac
PROTOBUFJS_REV=		e34549db516f8712f678fcd4bc411613b5cc5295
RE2_REV=		6dcd83d60f7944926bfd308cc13979fc53dd69ca
TESTING_REV=		63412fdcdfe281e6b9531a5e1086a59c0b9e6909
THIRD_PARTY_REV=	d212a71416ad7c6ceca04d6d27dfdd84fd00c04c
TOOLS_REV=		6820cc03cc8a4b1fb99747f30e8249d138a70981

BINARY_ALIAS=	vpython3=${PYTHON_CMD}

# Keep in sync with https://github.com/signalapp/ringrtc/blob/v${DISTVERSION}/bin/build-electron#L119
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
