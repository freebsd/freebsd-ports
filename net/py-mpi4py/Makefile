PORTNAME=	mpi4py
DISTVERSION=	4.1.0
CATEGORIES=	net parallel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	laurent.chardon@gmail.com
COMMENT?=	Python bindings for MPI (OpenMPI)
WWW=		https://github.com/mpi4py/mpi4py

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

USES=		pkgconfig python
USE_PYTHON=	autoplist concurrent cython3 distutils

LDFLAGS+=	${MPI_LIBS}

MP?=			OPENMPI
.if ${MP} == "OPENMPI"
USES+=			mpi:openmpi
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}mpi4py-mpich-4*
MPIOPTIONS=		--oversubscribe --stream-buffering 0
.elif ${MP} == "MPICH"
USES+=			fortran mpi:mpich
LDFLAGS+=		${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}mpi4py-4*
MPIOPTIONS=
.else
BROKEN=			invalid parameter MP
.endif

PORTDOCS=	*

#SLAVEDIRS=	net/py-mpi4py-mpich

OPTIONS_DEFINE=	DOCS

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
	(cd ${WRKSRC} && ${MPIEXEC} ${MPIOPTIONS} -n 5 ${PYTHON_CMD} test/main.py)

.include <bsd.port.mk>
