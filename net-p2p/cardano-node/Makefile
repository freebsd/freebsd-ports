PORTNAME=	cardano-node
PORTVERSION=	11.1.3
CATEGORIES=	net-p2p
MASTER_SITES=	https://chap.intersectmbo.org/package/:chap

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Core component of the Cardano decentralized blockchain
WWW=		https://cardano.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386

BUILD_DEPENDS=	ghc-9.6.7:lang/ghc96 \
		protoc:devel/protobuf
LIB_DEPENDS=	libsecp256k1.so:math/secp256k1 \
		libblst.so:security/blst \
		liblmdb.so:databases/lmdb0 \
		libsnappy.so:archivers/snappy
RUN_DEPENDS=	${LOCALBASE}/share/rc-subr-jail/rc.subr.jail:ports-mgmt/rc-subr-jail

USES=		autoreconf:build cabal gmake libtool pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	IntersectMBO

GH_TUPLE=	IntersectMBO:libsodium:${LIBSODIUM_HASH}:sodium

CARDANO_NODE_HASH=	938cba990357ae7c4b7f95c8f75dd9d31174bbeb
# taken from https://github.com/IntersectMBO/cardano-node/blob/938cba990357ae7c4b7f95c8f75dd9d31174bbeb/flake.lock#L1617
LIBSODIUM_HASH=		dbb48cce5429cb6585c9034f002568964f1ce567

USE_RC_SUBR=		cardano_node
LIBS_PREFIX=		${WRKDIR}/libs_install
BINARY_ALIAS=		git=true

USERS=		cardano
GROUPS=		cardano

CABAL_PROJECT=		append
CABAL_EXECUTABLES=	cardano-node cardano-submit-api cardano-tracer
CABAL_REPOSITORIES=	chap
BUILD_ARGS=		--ghc-option -Wwarn

WITH_LTO=	yes

post-patch:
	${REINPLACE_CMD} -e 's/$$(gitRevFromGit)/"${CARDANO_NODE_HASH}"/' \
			 -e '/Cardano.Git.RevFromGit/d' \
			 ${WRKSRC}/_cabal_deps/cardano-git-rev-0.2.2.1/src/Cardano/Git/Rev.hs

pre-build:
	@${MKDIR} ${PKGCONFIG_LINKDIR}

	cd ${WRKSRC_sodium} && ./autogen.sh
	cd ${WRKSRC_sodium} && ./configure --prefix=${LIBS_PREFIX} --with-pthreads --disable-shared
	cd ${WRKSRC_sodium} && ${GMAKE} -j${MAKE_JOBS_NUMBER} && ${GMAKE} ${INSTALL_TARGET}
	${MV} ${LIBS_PREFIX}/lib/pkgconfig/libsodium.pc ${PKGCONFIG_LINKDIR}

.include <bsd.port.mk>
