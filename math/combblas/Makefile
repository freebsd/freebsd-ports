PORTNAME=	CombBLAS
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
PORTREVISION=	2
MASTER_SITES=	https://portal.nersc.gov/project/m1982/CombBLAS/:test_data
CATEGORIES=	math
DISTFILES=	testdata_combblas1.6.1.tgz:test_data

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Combinatorial BLAS library: an extensible parallel graph library
WWW=		https://people.eecs.berkeley.edu/~aydin/CombBLAS/html/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	fails to build: uses x86 asm

LIB_DEPENDS=	libmpi.so:net/mpich
RUN_DEPENDS=	${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so.1:lang/gcc${GCC_DEFAULT} # because of the link flags induced by mpich

USES=		cmake:testing compiler:c++14-lang localbase:ldflags tar:tgz
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	PASSIONLab

CMAKE_ON=	BUILD_SHARED_LIBS

# many tests fail, see https://github.com/PASSIONLab/CombBLAS/issues/15

post-extract:
	@cd ${WRKSRC}/include && ${RM} .DS_Store ._.DS_Store CombBLAS/._CombBLAS.h

pre-test:
	@if [ ! -L ${TEST_WRKSRC}TESTDATA ]; then \
		${RLN} ${WRKDIR}/TESTDATA ${TEST_WRKSRC}/; \
	fi

.include <bsd.port.mk>
