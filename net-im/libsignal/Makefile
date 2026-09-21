PORTNAME=	libsignal
DISTVERSIONPREFIX=	v
DISTVERSION=	0.102.3
CATEGORIES=	net-im java

MAINTAINER=	jaap.aarts1@gmail.com
COMMENT=	Implementation of the Signal client protocol
WWW=		https://github.com/signalapp/libsignal

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	protoc:devel/protobuf
LIB_DEPENDS=	libclang.so:devel/llvm${LLVM_DEFAULT}

USES=		cargo

# BoringSSL ships no PowerPC assembly, so use the portable C implementations.
CFLAGS_powerpc64le=	-DOPENSSL_NO_ASM
CXXFLAGS_powerpc64le=	-DOPENSSL_NO_ASM
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
BROKEN_aarch64=Missing max_align_t in libc crate
BROKEN_i386= 	bindgen for boring-ssl fail
#CFLAGS_i386=	-DOPENSSL_NO_ASM
USE_LDCONFIG=	yes

# to get the GH_TUPLE
# git clone git@github.com:signalapp/boring.git
# cd boring
# git checkout correct_tag (grep boring Makefile.crates)
# git submodule update --init --recursive
# the hash for boringssl and fips should be printed on screen
# or browse https://github.com/signalapp/boring/tree/signal-v4.15.0/boring-sys/deps (with the correct tag)
GH_TUPLE=	google:boringssl:e2a57cfb4d915b4ba820585aef9fdee7bca13fe5:boringssl

CARGO_BUILD_ARGS=	--package libsignal-jni --package libsignal-ffi
MAKE_ENV=		CARGO_PROFILE_RELEASE_LTO=thin \
			OPENSSL_INCLUDE_DIR=${OPENSSLINC} \
			OPENSSL_LIB_DIR=${OPENSSLLIB} \
			RUSTC_BOOTSTRAP=aes,polyval

.include <bsd.port.options.mk>

post-extract:
	${MV} ${WRKDIR}/boringssl-e2a57cfb4d915b4ba820585aef9fdee7bca13fe5/* ${WRKDIR}/boring-signal-v5.2.0/boring-sys/deps/boringssl

do-install:
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/*/libsignal_ffi.a \
		${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/*/libsignal_jni.so \
		${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
