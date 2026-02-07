PORTNAME=	elk
DISTVERSION=	10.3.12
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}
PKGNAMESUFFIX=	-chemistry
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	All-electron full-potential linearised augmented-planewave code
WWW=		http://elk.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libblas.so:math/blas \
		libblis.so:math/blis \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas \
		libwannier.so:science/wannier90 \
		libxc.so:science/libxc

USES=		fortran gmake tar:tgz

BINARY_ALIAS=	make=${GMAKE}

LDFLAGS+=	${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so

OPTIONS_DEFINE=		DOCS EXAMPLES NATIVE OPENMP
OPTIONS_RADIO=		MPI
OPTIONS_RADIO_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	OPENMP MPICH
PARALLEL_DESC=		Enable parallelizations:

NATIVE_MAKE_ARGS=	FFLAGS="${FFLAGS} -march=native -mtune=native"
NATIVE_VARS=		FFLAGS="-march=native -mtune=native"

OPENMP_VARS=		OPENMP_FLAGS=-fopenmp

MPICH_USES=		mpi:mpich
MPICH_MAKE_ARGS=	F90=${MPIF90}

OPENMPI_USES=		mpi:openmpi
OPENMPI_MAKE_ARGS=	F90=${MPIF90}

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

do-test: # several tests fail, see https://sourceforge.net/p/elk/discussion/897822/thread/5d7862dd8b/
	@cd ${WRKSRC}/tests && ./test.sh

# 1 test (test_024) fails, reported to dewhurst@mpi-halle.mpg.de on 2026-06-26 (before was: see https://sourceforge.net/p/elk/discussion/897820/thread/f7b5859624/)

.include <bsd.port.post.mk>
