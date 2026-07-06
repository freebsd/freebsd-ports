PORTNAME=	ogmios
PORTVERSION=	7.0.0
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	net-p2p
MASTER_SITES=	https://input-output-hk.github.io/cardano-haskell-packages/package/:chap

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	WebSockets API to Cardano Ouroboros' mini-protocols
WWW=		https://ogmios.dev/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsecp256k1.so:math/secp256k1 \
		libblst.so:security/blst \
		liblmdb.so:databases/lmdb0
RUN_DEPENDS=	cardano-node:net-p2p/cardano-node

USES=		autoreconf:build cabal gmake libtool pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	cardanosolutions

GH_TUPLE=	CardanoSolutions:hjsonpointer:879f0e74d55eef76ceaec8f60ed07657ab84bad7:hjsonpointer/modules/hjsonpointer \
		CardanoSolutions:hjsonschema:fc9cfe92723e305e6289e7c1733f3420d64dd9d5:hjsonschema/modules/hjsonschema

GH_TUPLE+=	input-output-hk:libsodium:${LIBSODIUM_HASH}:sodium

LIBSODIUM_HASH=		dbb48cce5429cb6585c9034f002568964f1ce567

WRKSRC_SUBDIR=		server
USE_RC_SUBR=		ogmios
LIBS_PREFIX=		${WRKDIR}/libs_install
BINARY_ALIAS=		git=true

CABAL_PROJECT=		append
CABAL_REPOSITORIES=	chap

pre-build:
	@${MKDIR} ${PKGCONFIG_LINKDIR}

	cd ${WRKSRC_sodium} && ./autogen.sh
	cd ${WRKSRC_sodium} && ./configure --prefix=${LIBS_PREFIX} --with-pthreads --disable-shared
	cd ${WRKSRC_sodium} && ${GMAKE} -j${MAKE_JOBS_NUMBER} && ${GMAKE} ${INSTALL_TARGET}
	${MV} ${LIBS_PREFIX}/lib/pkgconfig/libsodium.pc ${PKGCONFIG_LINKDIR}

.include <bsd.port.mk>
