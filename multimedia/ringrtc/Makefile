PORTNAME=	ringrtc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.42.0
PORTREVISION=	1
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
WEBRTC_REV=	6261i

# modify webrtc_fetch.sh, then sh webrtc_fetch.sh
BASE_REV=		36ecc8e397422620def3bb19a7ba392810ca2442
BORINGSSL_REV=		414f69504d30d0848b69f6453ea7fb5e88004cb4
BUILD_REV=		28cd6ea727d171ec990e6174308451d4178d7f8e
BUILDTOOLS_REV=		aadc2aa5f7382cdb5bc8e9309971356cf7722773
CATAPULT_REV=		3e413d7b62c09fda8713146714ba2146a0369d86
ICU_REV=		a622de35ac311c5ad390a7af80724634e5dc61ed
LIBJPEG_TURBO_REV=	9b894306ec3b28cea46e84c32b56773a98c483da
LIBSRTP_REV=		5b7c744eb8310250ccc534f3f86a2015b3887a0a
LIBVPX_REV=		b95d17572629c676bdcfd535fb3990b9f6f8fb11
LIBYUV_REV=		04821d1e7d60845525e8db55c7bcd41ef5be9406
NASM_REV=		f477acb1049f5e043904b87b825c5915084a9a29
TESTING_REV=		450bfd79ee0369ac1a5465a12820b5d94a5956be
THIRD_PARTY_REV=	692fab5c0074bc6fa486dce1a4aa7b2cc5609928
OPUS_REV=		0e30966b198ad28943799eaf5b3b08100b6f70c3

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
NPM_RINGRTC_DIR=	npm-@signalapp-ringrtc-2.36.0-67d1b48bd4c1ea31c155ea14a0bd28f04e46eff5-integrity
NPM_SIGNAL_DIR=	npm-@signalapp-libsignal-client-0.39.1-15b41f15c516ae3eecf8a098a9c9c7aac00444d7-integrity
NPM_SQLITE3_DIR=	npm-@signalapp-better-sqlite3-8.6.0-0413f4d0626b99838cd64ad09c88720aa2bec6ed-integrity
SQLCIPHER=	sqlcipher-4.5.5-fts5-fix--3.0.7--0.2.1-ef53ea45ed92b928ecfd33c552d8d405263e86e63dec38e1ec63e1b0193b630b

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
