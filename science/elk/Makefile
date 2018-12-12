# $FreeBSD$

PORTNAME=	elk
DISTVERSION=	5.2.14
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/
PKGNAMESUFFIX=	-chemistry
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	All-electron full-potential linearised augmented-planewave code

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

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

post-patch:
	@${SED} 's|%%GMAKE%%|${GMAKE}|; s|%%FC%%|${FC}|; s|%%OPENMP_FLAGS%%|${OPENMP_FLAGS}|' \
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
	@cd ${WRKSRC}/tests && ./tests.sh

.include <bsd.port.mk>
