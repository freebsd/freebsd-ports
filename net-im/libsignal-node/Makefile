PORTNAME=	libsignal
DISTVERSIONPREFIX=	v
DISTVERSION=	0.76.7
CATEGORIES=	net-im
MASTER_SITES=	LOCAL/mikael/signal-desktop/:npm
PKGNAMESUFFIX=	-node
DISTFILES=	libsignal-node-${DISTVERSION}-npm-cache.tar.gz:npm

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Platform-agnostic APIs used by the official Signal clients and servers
WWW=		https://github.com/signalapp/libsignal

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

EXTRACT_DEPENDS=npm:www/npm${NODEJS_SUFFIX}
BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT} \
		npm:www/npm${NODEJS_SUFFIX} \
		protoc:devel/protobuf

USES=		cargo gmake nodejs:20,build python:build
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
# to get the GH_TUPLE
# git clone git@github.com:signalapp/boring.git
# cd boring
# git checkout correct_tag (grep boring Makefile.crates)
# git submodule update --init --recursive
# the hash for boringssl and fips should be printed on screen
# or browse https://github.com/signalapp/boring/tree/signal-v4.15.0/boring-sys/deps (with the correct tag)
GH_TUPLE=	google:boringssl:44b3df6f03d85c901767250329c571db405122d5:boringssl \
		google:boringssl:853ca1ea1168dff08011e5d42d94609cc0ca2e27:boringssl_fips

# RUSTFLAGS=-Clink-dead-code is required to have a functional libsignal-node binary:
# linkme is broken with https://github.com/dtolnay/linkme/commit/64e7c63c106848481bea8f66c4885b52c26ca9ec
# It's probably related to https://github.com/dtolnay/linkme/issues/49
MAKE_ENV=	HOME=${WRKDIR} \
		PYTHON=${PYTHON_CMD} \
		RUSTFLAGS=-Clink-dead-code \
		XDG_CACHE_HOME=${WRKDIR}/.cache

MAKE_ENV+=	RUSTC_BOOTSTRAP=aes,polyval

USE_LDCONFIG=	yes

PLIST_FILES=	lib/libsignal_node.so

NODE_ARCH=	${ARCH:S/aarch64/arm64/:S/amd64/x64/}
RUST_ARCH=	${ARCH:S/amd64/x86_64/}

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} "s#python3#${PYTHON_CMD}#" \
		${WRKSRC}/node/binding.gyp

# to get the hash:
# fetch -o - https://raw.githubusercontent.com/signalapp/libsignal/v0.67.4/Cargo.lock | grep https://github.com/signalapp/boring
post-extract:
	${MV} ${WRKDIR}/boringssl-44b3df6f03d85c901767250329c571db405122d5/* ${WRKDIR}/boring-signal-v4.15.0/boring-sys/deps/boringssl
	${MV} ${WRKDIR}/boringssl-853ca1ea1168dff08011e5d42d94609cc0ca2e27/* ${WRKDIR}/boring-signal-v4.15.0/boring-sys/deps/boringssl-fips

do-build:
	${ECHO_CMD} offline=true >> ${WRKSRC}/.npmrc
	cd ${WRKSRC}/node && \
		${SETENV} ${MAKE_ENV} npm install --ignore-optional --nodedir=${LOCALBASE}
	cd ${WRKSRC}/node && \
		${SETENV} ${MAKE_ENV} npx node-gyp rebuild --nodedir=${LOCALBASE}
	cd ${WRKSRC}/node && \
		${SETENV} ${MAKE_ENV} npm run tsc

do-install:
	${INSTALL_DATA} ${WRKSRC}/node/build/Release/obj.target/libsignal_client_freebsd_${NODE_ARCH}.node/geni/rust/${RUST_ARCH}-unknown-freebsd/release/libsignal_node.so \
		${STAGEDIR}${PREFIX}/lib/

create-caches-tarball:
	# do some cleanup first
	${RM} -r ${WRKDIR}/.npm/_logs ${WRKDIR}/.npm/_update-notifier-last-checked

	cd ${WRKDIR} && \
		${TAR} czf libsignal-node-${DISTVERSION}-npm-cache.tar.gz .npm

.include <bsd.port.mk>
