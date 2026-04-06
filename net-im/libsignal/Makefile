PORTNAME=	libsignal
DISTVERSIONPREFIX=	v
DISTVERSION=	0.87.5
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
GH_TUPLE=	google:boringssl:91a66a59b6c1435120ff83e245d7719411294386:boringssl \

CARGO_BUILD_ARGS=	--package libsignal-jni --package libsignal-ffi
MAKE_ENV=		CARGO_PROFILE_RELEASE_LTO=thin \
			OPENSSL_INCLUDE_DIR=${OPENSSLINC} \
			OPENSSL_LIB_DIR=${OPENSSLLIB} \
			RUSTC_BOOTSTRAP=aes,polyval
PLIST_FILES=		lib/libsignal_ffi.a lib/libsignal_jni.so

.include <bsd.port.options.mk>

post-extract:
	${MV} ${WRKDIR}/boringssl-91a66a59b6c1435120ff83e245d7719411294386/* ${WRKDIR}/boring-signal-v5.0.2/boring-sys/deps/boringssl

do-install:
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/*/libsignal_ffi.a \
		${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/*/libsignal_jni.so \
		${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
