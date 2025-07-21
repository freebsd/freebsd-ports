PORTNAME=	spglib
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for finding and handling crystal symmetries
WWW=		https://spglib.github.io/spglib/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing
USE_GITHUB=	yes
USE_LDCONFIG=	yes

TEST_DEPENDS=	googletest>0:devel/googletest

CMAKE_OFF=	SPGLIB_WITH_TESTS
CMAKE_TESTING_ON=	SPGLIB_WITH_TESTS

.if !exists(/usr/include/omp.h)
CMAKE_OFF+=	SPGLIB_USE_OMP
.else
FORTRAN_LDFLAGS=	-lomp # workaround for: undefined reference to `__kmpc_fork_call'
.endif

OPTIONS_DEFINE=		FORTRAN
OPTIONS_DEFAULT=	FORTRAN
OPTIONS_SUB=		yes

FORTRAN_USES=		fortran
FORTRAN_CMAKE_BOOL=	SPGLIB_WITH_Fortran

# tests as of 2.6.0: 100% tests passed, 0 tests failed out of 59

.include <bsd.port.mk>
