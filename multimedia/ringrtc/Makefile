PORTNAME=	ringrtc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.34.4
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
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

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
WEBRTC_REV=	5845j

# modify webrtc_fetch.sh, then sh webrtc_fetch.sh
BASE_REV=		609cafa975c8a29d3b2f686c9a42530a556835fe
BORINGSSL_REV=		b8e012e1ff736cc794273af4a7db521e6b18bcd5
BUILD_REV=		115a7079919c25462a7fd8c1d22900378bbc6585
BUILDTOOLS_REV=		b2043d4f435131d0a1bdd5342c17753ef9236572
CATAPULT_REV=		b8c4f2d99ac66fe47cb8cceec0dd1a1da5d1b51e
ICU_REV=		985b9a6f70e13f3db741fed121e4dcc3046ad494
LIBJPEG_TURBO_REV=	30bdb85e302ecfc52593636b2f44af438e05e784
LIBSRTP_REV=		5b7c744eb8310250ccc534f3f86a2015b3887a0a
LIBVPX_REV=		38a707faef72eeff89d669c553e7bfe9e08dba8f
LIBYUV_REV=		04821d1e7d60845525e8db55c7bcd41ef5be9406
NASM_REV=		7fc833e889d1afda72c06220e5bed8fb43b2e5ce
TESTING_REV=		ff8dee88bc0b49f8337cee6e82151c245a63b98c
THIRD_PARTY_REV=	ee6367daea550c5845a6079cec5fd6555f39144f
OPUS_REV=		74d8597f47aa680c9f9e21ab0b99c8c0632fe27d

BINARY_ALIAS=	vpython3=${PYTHON_CMD}

# Keep in sync with https://github.com/signalapp/ringrtc/blob/v${DISTVERSION}/bin/build-electron#L101
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
		rtc_libvpx_build_vp9=true \
		rtc_include_ilbc=false \
		use_custom_libcxx=false \
		is_debug=false \
		is_clang=true \
		clang_use_chrome_plugins=false \
		treat_warnings_as_errors=false \
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
