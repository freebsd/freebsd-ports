# $FreeBSD$

PORTNAME=	mpi4py
DISTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	net parallel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	Python bindings for MPI

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

USES=		python
USE_PYTHON=	distutils cython autoplist concurrent

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_SINGLE=		MP
OPTIONS_SINGLE_MP=	MPICH2 OPENMPI OPENMPI2
OPTIONS_DEFAULT=	OPENMPI # the only non-failing MPI implementation
MP_DESC=		MPI Implementation

MPICH2_USES=		fortran
MPICH2_LIB_DEPENDS=	libmpich.so:net/mpich2
MPICH2_LDFLAGS=		${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so

OPENMPI_LIB_DEPENDS=	libmpi.so:net/openmpi

OPENMPI2_DESC=		${OPENMPI_DESC} 2.x
OPENMPI2_LIB_DEPENDS=	libmpi.so:net/openmpi2

PORTDOCS=		*

do-patch-OPENMPI-on:
	@${CP} ${FILESDIR}/mpi.cfg ${WRKSRC}/
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/mpi.cfg

do-patch-OPENMPI2-on:
	@${CP} ${FILESDIR}/mpi2.cfg ${WRKSRC}/mpi.cfg
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/mpi.cfg

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	@${RM} ${STAGEDIR}${DOCSDIR}/${PORTNAME}.1

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	@${ECHO} man/man1/mpi4py.1.gz >> ${TMPPLIST}

post-install:
	@cd ${STAGEDIR}${PYTHON_SITELIBDIR}/mpi4py && ${STRIP_CMD} dl.so MPI.so lib-pmpi/libvt-hyb.so lib-pmpi/libvt.so lib-pmpi/libvt-mpi.so lib-pmpi/libmpe.so

do-test:
	# tests fail with MPICH2=on: https://bitbucket.org/mpi4py/mpi4py/issues/110/tests-fail-with-mpich2-on-freebsd-error
	# tests fail with OPENMPI2=on: https://bitbucket.org/mpi4py/mpi4py/issues/109/tests-fail-with-openmpi2-on-freebsd
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
