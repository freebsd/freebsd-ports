PORTNAME=	xtb
DISTVERSIONPREFIX=	v
DISTVERSION=	6.7.1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Semiempirical Extended Tight-Binding Program Package
WWW=		https://github.com/grimme-lab/xtb

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmctc-lib.so:science/mctc-lib
BUILD_DEPENDS=	test-drive>0:devel/test-drive
TEST_DEPENDS=	test-drive>0:devel/test-drive

USES=		cmake:testing fortran blaslapack:openblas

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

CMAKE_OFF=	WITH_TBLITE WITH_CPCMX

USE_GITHUB=	yes
GH_ACCOUNT=	grimme-lab

USE_LDCONFIG=	yes
FFLAGS+=	-std=legacy

# tests as of 6.7.1: 100% tests passed, 0 tests failed out of 34

.include <bsd.port.mk>
