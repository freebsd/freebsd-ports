PORTNAME=	libsignal
DISTVERSIONPREFIX=	v
DISTVERSION=	0.84.0
PORTREVISION=	1
CATEGORIES=	net-im java

MAINTAINER=	jaap.aarts1@gmail.com
COMMENT=	Implementation of the Signal client protocol
WWW=		https://github.com/signalapp/libsignal

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT} \
		protoc:devel/protobuf

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
USE_LDCONFIG=	yes

# to get the GH_TUPLE
# git clone git@github.com:signalapp/boring.git
# cd boring
# git checkout correct_tag (grep boring Makefile.crates)
# git submodule update --init --recursive
# the hash for boringssl and fips should be printed on screen
# or browse https://github.com/signalapp/boring/tree/signal-v4.15.0/boring-sys/deps (with the correct tag)
GH_TUPLE=	google:boringssl:44b3df6f03d85c901767250329c571db405122d5:boringssl \
		google:boringssl:853ca1ea1168dff08011e5d42d94609cc0ca2e27:boringssl_fips

CARGO_BUILD_ARGS=	--package libsignal-jni --package libsignal-ffi
MAKE_ENV=		CARGO_PROFILE_RELEASE_LTO=thin \
			OPENSSL_INCLUDE_DIR=${OPENSSLINC} \
			OPENSSL_LIB_DIR=${OPENSSLLIB} \
			RUSTC_BOOTSTRAP=aes,polyval
PLIST_FILES=		lib/libsignal_jni.so

.include <bsd.port.options.mk>

post-extract:
	${MV} ${WRKDIR}/boringssl-44b3df6f03d85c901767250329c571db405122d5/* ${WRKDIR}/boring-signal-v4.18.0/boring-sys/deps/boringssl
	${MV} ${WRKDIR}/boringssl-853ca1ea1168dff08011e5d42d94609cc0ca2e27/* ${WRKDIR}/boring-signal-v4.18.0/boring-sys/deps/boringssl-fips

do-install:
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/*/libsignal_jni.so \
		${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
