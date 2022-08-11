PORTNAME=	arpack-ng
DISTVERSION=	3.8.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Revised Argand library for solving large-scale eigenvalue problems

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpich.so:net/mpich # MPI is incremental: it adds the libparpack.so lib, it is a candidate for a sub-package

USES=		autoreconf fortran libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	opencollab
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-blas="${BLAS}" \
		--with-lapack="${LAPACK}" \
		--enable-mpi \
		--disable-static \
		--enable-icb
LDFLAGS+=	-L${LOCALBASE}/lib
TEST_TARGET=	check
USE_LDCONFIG=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

CONFLICTS_INSTALL=	arpack

OPTIONS_DEFINE=	DOCS EXAMPLES

WITH_BLAS?=	blas

.if ${WITH_BLAS} == "gotoblas"
BLAS=		-lgoto2p
LAPACK=		-lgoto2p
LIB_DEPENDS+=	libgoto2p.so:math/gotoblas
.elif ${WITH_BLAS} == "atlas"
BLAS=		-lptf77blas
LAPACK=		-lalapack -lptcblas
LIB_DEPENDS+=	libptf77blas.so:math/atlas
.elif ${WITH_BLAS} == "blas"
BLAS=		-lblas
LAPACK=		-llapack
LIB_DEPENDS+=	libblas.so:math/blas \
		liblapack.so:math/lapack
.else
IGNORE=		unknown value of WITH_BLAS: ${WITH_BLAS}
.endif

pre-configure:
	@cd ${WRKSRC}; ./bootstrap

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*arpack.so.*.*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/DOCUMENTS && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/EXAMPLES && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
