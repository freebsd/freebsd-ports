PORTNAME=	cardano-cli
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	11.0.0.0
PORTREVISION=	1
CATEGORIES=	sysutils net-p2p
MASTER_SITES=	https://chap.intersectmbo.org/package/:chap

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Command line management tool for Cardano node
WWW=		https://cardano.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386

LIB_DEPENDS=	libsecp256k1.so:math/secp256k1 \
		libblst.so:security/blst \
		liblmdb.so:databases/lmdb0

USES=		autoreconf:build cabal gmake libtool pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	IntersectMBO

GH_TUPLE=	IntersectMBO:libsodium:${LIBSODIUM_HASH}:sodium

LIBSODIUM_HASH=	dbb48cce5429cb6585c9034f002568964f1ce567

LIBS_PREFIX=	${WRKDIR}/libs_install

CABAL_PROJECT=		append
CABAL_REPOSITORIES=	chap

BUILD_ARGS=		--ghc-option -Wwarn

WITH_LTO=	yes

pre-build:
	@${MKDIR} ${PKGCONFIG_LINKDIR}

	cd ${WRKSRC_sodium} && ./autogen.sh
	cd ${WRKSRC_sodium} && ./configure --prefix=${LIBS_PREFIX} --with-pthreads --disable-shared
	cd ${WRKSRC_sodium} && ${GMAKE} -j${MAKE_JOBS_NUMBER} && ${GMAKE} ${INSTALL_TARGET}
	${MV} ${LIBS_PREFIX}/lib/pkgconfig/libsodium.pc ${PKGCONFIG_LINKDIR}

.include <bsd.port.mk>
