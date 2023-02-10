PORTNAME=	Aluminum
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic interface to high-performance communication libraries
WWW=		https://github.com/LLNL/Aluminum

LICENSE=	APACHE20

LIB_DEPENDS=	libhwloc.so:devel/hwloc2
TEST_DEPENDS=	cxxopts>0:devel/cxxopts

USES=		cmake:testing compiler:c++17-lang mpi:openmpi
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL

CMAKE_TESTING_ON=	ALUMINUM_ENABLE_TESTS

LDFLAGS+=	-lexecinfo

post-test:
.for t in test_exchange test_ops; do
	@cd ${TEST_WRKSRC}/test && ./${t}
.endfor

.include <bsd.port.mk>
