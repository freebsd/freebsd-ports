PORTNAME=	arpack-ng
DISTVERSION=	3.9.1
PORTREVISION=	6
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Revised Argand library for solving large-scale eigenvalue problems
WWW=		https://github.com/opencollab/arpack-ng

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	mpich openmpi nompi
FLAVOR?=	${FLAVORS:[1]}
mpich_PKGNAMESUFFIX=	-mpich
openmpi_PKGNAMESUFFIX=	-openmpi
nompi_PKGNAMESUFFIX=	-nompi

USES=		autoreconf eigen:3 fortran libtool localbase pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	opencollab

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-blas="${BLASLIB}" \
		--with-lapack="${LAPACKLIB}" \
		--disable-static \
		--enable-icb

.if ${FLAVOR} == mpich
USES+=			mpi:mpich
CONFIGURE_ARGS+=	--enable-mpi \
			--with-mpi=${MPI_PREFIX} \
			--with-mpi-lib="${MPI_LIBS}" \
			--with-mpi-include="${MPI_INCLUDES}" # these are not respected, see https://github.com/opencollab/arpack-ng/issues/479
CFLAGS+=		${MPI_CFLAGS}
FFLAGS+=		${MPI_CFLAGS}
FCFLAGS+=		${MPI_CFLAGS}
LDFLAGS+=		${MPI_LIBS}
PATH=			"${MPI_HOME}/bin::/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/bin"
PLIST_FILES=		include/arpack/parpack.h \
			include/arpack/parpack.hpp \
			lib/libparpack.so \
			lib/libparpack.so.2 \
			lib/libparpack.so.2.1.0
.endif

.if ${FLAVOR} == openmpi
USES+=			mpi:openmpi
CONFIGURE_ARGS+=	--enable-mpi \
			--with-mpi=${MPI_PREFIX} \
			--with-mpi-lib="${MPI_LIBS}" \
			--with-mpi-include="${MPI_INCLUDES}" # these are not respected, see https://github.com/opencollab/arpack-ng/issues/479
CFLAGS+=		${MPI_CFLAGS}
FFLAGS+=		${MPI_CFLAGS}
FCFLAGS+=		${MPI_CFLAGS}
LDFLAGS+=		${MPI_LIBS}
PATH=			"${MPI_HOME}/bin::/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/bin"
PLIST_FILES=		include/arpack/parpack.h \
			include/arpack/parpack.hpp \
			lib/libparpack.so \
			lib/libparpack.so.2 \
			lib/libparpack.so.2.1.0
CONFLICTS_BUILD=	mpich
.endif

TEST_TARGET=	check

PIE_UNSAFE=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

CONFLICTS_INSTALL=	arpack

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_SINGLE=		BLASLIB

OPTIONS_SINGLE_BLASLIB=	ATLAS NETLIB OPENBLAS
OPTIONS_DEFAULT=	NETLIB
ATLAS_USES=		blaslapack:atlas
NETLIB_USES=		blaslapack:netlib
OPENBLAS_USES=		blaslapack:openblas

pre-configure:
	cd ${WRKSRC} && ./bootstrap

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
