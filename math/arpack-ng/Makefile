PORTNAME=	arpack-ng
DISTVERSION=	3.9.1
PORTREVISION=	7
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Revised Argand library for solving large-scale eigenvalue problems
WWW=		https://github.com/opencollab/arpack-ng

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	bash:shells/bash

FLAVORS=	nompi mpich openmpi
FLAVOR?=	nompi
mpich_PKGNAMESUFFIX=	-mpich
openmpi_PKGNAMESUFFIX=	-openmpi
nompi_PKGNAMESUFFIX=	-nompi

USES=		cmake:testing eigen:3 fortran libtool localbase pkgconfig	\
		shebangfix
SHEBANG_FILES=	cmake/tstCMakeInstall.sh.in	\
		pkg-config/tstAutotoolsInstall.sh.in	\
		EXAMPLES/MATRIX_MARKET/*.sh
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	opencollab

TEST_TARGET=	check

PIE_UNSAFE=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

CONFLICTS_INSTALL=	arpack

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_SINGLE=		BLASLIB

OPTIONS_SINGLE_BLASLIB=	NETLIB OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS
OPTIONS_SUB=		yes

NETLIB_USES=		blaslapack:netlib
OPENBLAS_USES=		blaslapack:openblas
PYTHON_LIB_DEPENDS=	${PY_BOOST}	\
			libboost_graph.so:devel/boost-libs
PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	PYTHON3

.if ${FLAVOR} == nompi
CMAKE_ON+=		EIGEN ICB
OPTIONS_DEFINE+=	PYTHON
OPTIONS_DEFAULT+=	PYTHON
PLIST_SUB+=		NOMPI="@comment " MPI=""
.else
CMAKE_ON+=		MPI
CFLAGS+=		${MPI_CFLAGS}
FFLAGS+=		${MPI_CFLAGS}
FCFLAGS+=		${MPI_CFLAGS}
LDFLAGS+=		${MPI_LIBS}
PATH=			"${MPI_HOME}/bin::/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/bin"
PLIST_SUB+=		MPI="@comment " NOMPI="" PYTHON="@comment "
.endif

.if ${FLAVOR} == mpich
USES+=		mpi:mpich
.endif

.if ${FLAVOR} == openmpi
USES+=		mpi:openmpi
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*arpack.so.*.*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/DOCUMENTS && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/EXAMPLES && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

# tests as of 3.9.1:
# TOTAL: 8
# PASS:  8
# SKIP:  0
# XFAIL: 0
# FAIL:  0
# XPASS: 0
# ERROR: 0

.include <bsd.port.mk>
