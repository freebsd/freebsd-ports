# $FreeBSD$

PORTNAME=	mpi4py
DISTVERSION=	3.0.3
PORTREVISION=	1
CATEGORIES=	net parallel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for MPI

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

USES=		python:3.6+
USE_PYTHON=	distutils cython autoplist concurrent
LDFLAGS+=	${MPI_LIBS}

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_SINGLE=		MP
OPTIONS_SINGLE_MP=	MPICH OPENMPI
OPTIONS_DEFAULT=	OPENMPI # the only non-failing MPI implementation
MP_DESC=		MPI Implementation

MPICH_USES=		fortran mpi:mpich
MPICH_LDFLAGS=		${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so

OPENMPI_USES=		mpi:openmpi

PORTDOCS=		*

pre-configure:
	${CP} ${FILESDIR}/mpi.cfg ${WRKSRC}/
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%/mpi/openmpi|${MPI_HOME}|'	\
		${WRKSRC}/mpi.cfg

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	@${RM} ${STAGEDIR}${DOCSDIR}/${PORTNAME}.1

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	@${ECHO} man/man1/mpi4py.1.gz >> ${TMPPLIST}

post-install:
	@cd ${STAGEDIR}${PYTHON_SITELIBDIR}/mpi4py && ${STRIP_CMD} dl*.so MPI*.so lib-pmpi/libvt-hyb*.so lib-pmpi/libvt*.so lib-pmpi/libvt-mpi*.so lib-pmpi/libmpe*.so

do-test:
	# tests fail with MPICH2=on: https://bitbucket.org/mpi4py/mpi4py/issues/110/tests-fail-with-mpich2-on-freebsd-error
	# tests fail with OPENMPI2=on: https://bitbucket.org/mpi4py/mpi4py/issues/109/tests-fail-with-openmpi2-on-freebsd
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
