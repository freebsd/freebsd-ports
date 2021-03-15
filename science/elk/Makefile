# $FreeBSD$

PORTNAME=	elk
DISTVERSION=	7.1.14
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/
PKGNAMESUFFIX=	-chemistry
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	All-electron full-potential linearised augmented-planewave code

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libblis.so:math/blis \
		libopenblas.so:math/openblas \
		libwannier.so:science/wannier90

USES=		fortran gmake tar:tgz

BINARY_ALIAS=	make=${GMAKE}

LDFLAGS+=	${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so

OPTIONS_GROUP=		PARALLEL
OPTIONS_GROUP_PARALLEL=	OPENMP MPI
OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	${OPTIONS_GROUP_PARALLEL}
PARALLEL_DESC=		Enable parallelizations:

OPENMP_VARS=		OPENMP_FLAGS=-fopenmp
MPI_RUN_DEPENDS=	mpirun:net/mpich

PORTDOCS=		*
PORTEXAMPLES=		*

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=		bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch in argument 'cc' at (1); passed COMPLEX(8) to REAL(8)
FCFLAGS+=	-fallow-argument-mismatch
.endif

post-patch:
	@${SED} 's|%%GMAKE%%|${GMAKE}|; s|%%FC%%|${FC}|; \
		s|%%FCFLAGS%%|${FCFLAGS}|; \
		s|%%OPENMP_FLAGS%%|${OPENMP_FLAGS}|' \
		< ${FILESDIR}/make.inc.in \
		> ${WRKSRC}/make.inc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

do-test:
	@cd ${WRKSRC}/tests && ./test.sh

.include <bsd.port.post.mk>
