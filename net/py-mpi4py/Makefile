PORTNAME=	mpi4py
DISTVERSION=	4.0.0
CATEGORIES=	net parallel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	laurent.chardon@gmail.com
COMMENT?=	Python bindings for MPI (OpenMPI)
WWW=		https://github.com/mpi4py/mpi4py

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython3>3.0.0:lang/cython3@${PY_FLAVOR}

USES=		pkgconfig python
USE_PYTHON=	autoplist concurrent distutils

MP?=			OPENMPI
.if ${MP} == "OPENMPI"
USES+=			mpi:openmpi
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}mpi4py-mpich-4*
.elif ${MP} == "MPICH"
USES+=			fortran mpi:mpich
LDFLAGS+=		${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}mpi4py-4*
.else
BROKEN=			invalid parameter MP
.endif

LDFLAGS+=	${MPI_LIBS}

#SLAVEDIRS=	net/py-mpi4py-mpich

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

pre-configure:
	${CP} ${FILESDIR}/mpi.cfg ${WRKSRC}/
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%/mpi/openmpi|${MPI_HOME}|'	\
		${WRKSRC}/mpi.cfg

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install:
	(cd ${STAGEDIR}${PYTHON_SITELIBDIR}/mpi4py && ${STRIP_CMD} *.so)

do-test:
	(cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
