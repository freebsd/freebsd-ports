PORTNAME=	precice
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.1
CATEGORIES=	science # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Coupling library for partitioned multi-physics simulations
WWW=		https://precice.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libgcc_s.so:lang/gcc${GCC_DEFAULT}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		cmake:noninja,testing compiler:c++14-lang eigen:3 gnome mpi:openmpi pkgconfig python shebangfix # fails with ninja: phony target 'binprecice' names itself as an input; ignoring
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes

SHEBANG_FILES=	tools/profiling/precice-profiling

CMAKE_OFF=	BUILD_TESTING PRECICE_ENABLE_FORTRAN PRECICE_PythonActions

OPTIONS_DEFINE=	PETSC EXAMPLES

PETSC_DESC=		Use PETSc linear algebra library
PETSC_CMAKE_BOOL=	PRECICE_FEATURE_PETSC_MAPPING
PETSC_LIB_DEPENDS=	libpetsc.so:science/PETSc

PORTEXAMPLES=		*

post-install: # remove files which aren't docs
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
