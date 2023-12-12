PORTNAME=	NTPoly
DISTVERSIONPREFIX=	${PORTNAME:tl}-v
DISTVERSION=	3.0.0
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Library for computing the functions of sparse matrices
WWW=		https://william-dawson.github.io/NTPoly

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	swig>0:devel/swig
TEST_DEPENDS=	${PYNUMPY}	\
		bash:shells/bash	\
		${PYTHON_PKGNAMEPREFIX}mpi4py>0:net/py-mpi4py@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	william-dawson

USES=		blaslapack:openblas cmake fortran mpi python
FFLAGS+=	-fopenmp -fallow-argument-mismatch
CXXFLAGS+=	-fopenmp
CMAKE_ARGS=	-DCMAKE_TOOLCHAIN_FILE=${TOOLCHAIN}
CMAKE_ON=	BUILD_SHARED_LIBS
USE_LDCONFIG=	yes

TOOLCHAIN=	${WRKSRC}/Targets/${OPSYS}.cmake

NTPLIBS=	${PORTNAME} ${PORTNAME}CPP ${PORTNAME}Wrapper

pre-configure:
	${ECHO_CMD} 'set(CMAKE_SYSTEM_NAME ${OPSYS})' > ${TOOLCHAIN}
	${ECHO_CMD} 'set(CMAKE_C_COMPILER ${MPICC})' >> ${TOOLCHAIN}
	${ECHO_CMD} 'set(CMAKE_Fortran_COMPILER ${MPIFC})' >> ${TOOLCHAIN}
	${ECHO_CMD} 'set(CMAKE_CXX_COMPILER ${MPICXX})' >> ${TOOLCHAIN}
	${ECHO_CMD} 'set(TOOLCHAIN_LIBS "${BLASLIB}")' >> ${TOOLCHAIN}
	${ECHO_CMD} 'set(F_TOOLCHAINFLAGS_RELEASE "${FFLAGS}")' >> ${TOOLCHAIN}
	${ECHO_CMD} 'set(CXX_TOOLCHAINFLAGS_DEBUG "${CXXFLAGS}")' >> ${TOOLCHAIN}
	${ECHO_CMD} 'set(F_TOOLCHAINFLAGS_DEBUG "${FFLAGS}")' >> ${TOOLCHAIN}
	${ECHO_CMD} 'set(TARGET_SUPPORTS_SHARED_LIBS Yes)' >> ${TOOLCHAIN}

post-install:
.for l in ${NTPLIBS}
	${MV} ${STAGEDIR}${PREFIX}/lib/lib${l}.so	\
		${STAGEDIR}${PREFIX}/lib/lib${l}.so.0
	${RLN} ${STAGEDIR}${PREFIX}/lib/lib${l}.so.0	\
		${STAGEDIR}${PREFIX}/lib/lib${l}.so
.endfor

do-test:
	@${ECHO_MSG} "/!\\ WARNING /!\\"
	@${ECHO_MSG} "net/py-mpi4py must be built against MPICH!"
	cd ${BUILD_WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
