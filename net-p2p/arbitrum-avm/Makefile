PORTNAME=	arbitrum-avm
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p
MASTER_SITES=	LOCAL/nc/mirror/ \
		https://neel.my.to/mirror/arbitrum/
DISTNAME=	arbitrum-${PORTVERSION}

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Arbitrum Virtual Machine

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ethash>0:net-p2p/ethash \
		git:devel/git \
		intx>0:math/intx \
		microsoft-gsl>0:devel/microsoft-gsl
LIB_DEPENDS=	libbenchmark.so:devel/benchmark \
		libboost_system.so:devel/boost-libs \
		libgtest.so:devel/googletest \
		librocksdb.so:databases/rocksdb \
		libsecp256k1.so:math/secp256k1
RUN_DEPENDS=	ethash>0:net-p2p/ethash \
		intx>0:math/intx

USES=		cmake

CMAKE_OFF=	HUNTER_ENABLED
CMAKE_SOURCE_PATH=	${WRKSRC}/packages/arb-avm-cpp

PLIST_FILES=	bin/arbcore_runner \
		bin/avm_runner \
		bin/avm_tests

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/arbcore_runner \
		${STAGEDIR}${PREFIX}/bin/arbcore_runner
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/avm_runner \
		${STAGEDIR}${PREFIX}/bin/avm_runner
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/avm_tests \
		${STAGEDIR}${PREFIX}/bin/avm_tests

.include <bsd.port.mk>
