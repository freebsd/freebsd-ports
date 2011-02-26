# New ports collection makefile for:    sdpara
# Date created:                         March 17 2003
# Whom:                                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdpara
PORTVERSION=	7.2.1
PORTREVISION=	4
CATEGORIES=	math parallel
MASTER_SITES=	http://sdpa.indsys.chuo-u.ac.jp/sdpa/files/
DISTFILES=	${SRCFILE}#${MANUALFILE}
DIST_SUBDIR=	sdpa
EXTRACT_ONLY=	${SRCFILE}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SDPARA paralell version of SDPA (math/sdpa)

LIB_DEPENDS=	scalapack:${PORTSDIR}/math/scalapack \
		blacs:${PORTSDIR}/math/blacs \
		mpich:${PORTSDIR}/net/mpich2

.include <bsd.port.pre.mk>

SRCDATE=	20090109
MANDATE=	20080618
MANUALVER=	7.1.1
SRCFILE=	${PORTNAME}.${PORTVERSION}.src.${SRCDATE}.tar.gz
#MANUALFILE=	${PORTNAME}.${MANUALVER}.manual.${MANDATE}.pdf
USE_FORTRAN=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}
USE_BLAS?=	reference

.if exists(${LOCALBASE}/lib/libgoto2.so)
USE_BLAS=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas_r.so)
USE_BLAS=	atlas
.endif

. if ${USE_BLAS} == reference
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${USE_BLAS} == gotoblas
LIB_DEPENDS+=	goto2:${PORTSDIR}/math/gotoblas
BLAS=		-lgoto2p
LAPACK=		-lgoto2p
.elif ${USE_BLAS} == atlas
LIB_DEPENDS+=	atlas:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas -lptcblas -latlas_r
LAPACK=		-lalapack_r
.endif

#PLIST_SUB+=	MANUALFILE=${MANUALFILE}

SCALAPACK=	-L/usr/local/lib -lscalapack -lblacs -lblacsc
FORTRAN_LIBS=	-lgfortran
GCCLIBDIR=	-L`${CAT} ${WRKSRC}/LIBDIR` -L`${CAT} ${WRKSRC}/LIBDIR`/../../..

post-patch:
	@${REINPLACE_CMD} -e 's|%%MPICC%%|${LOCALBASE}/bin/mpicc|g ; \
				s|%%MPICXX%%|${LOCALBASE}/bin/mpicxx|g ; \
				s|%%MPIF77%%|${LOCALBASE}/bin/mpif77|g ; \
				s|%%CFLAGS%%|${CFLAGS}|g ; \
				s|%%CXXFLAGS%%|${CXXFLAGS}|g ; \
				s|%%FFLAGS%%|${FFLAGS}|g ; \
				s|%%BLAS%%|${BLAS}|g ; \
				s|%%LAPACK%%|${LAPACK}|g ; \
				s|%%SCALAPACK%%|${SCALAPACK}|g ; \
				s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g ; \
				s|%%FORTRAN_LIBS%%|${GCCLIBDIR} ${FORTRAN_LIBS}|g '  ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|%%MPICC%%|${LOCALBASE}/bin/mpicc|g ; \
				s|%%MPICXX%%|${LOCALBASE}/bin/mpicxx|g ; \
				s|%%MPIF77%%|${LOCALBASE}/bin/mpif77|g ; \
				s|%%CFLAGS%%|${CFLAGS}|g ; \
				s|%%CXXFLAGS%%|${CXXFLAGS}|g ; \
				s|%%FFLAGS%%|${FFLAGS}|g ; \
				s|%%BLAS%%|${BLAS}|g ; \
				s|%%LAPACK%%|${LAPACK}|g ' ${WRKSRC}/mumps/Makefile

pre-build:
	${DIRNAME} `${F77} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR

do-build:
	cd ${WRKSRC} ; ${GMAKE} mumps
	cd ${WRKSRC} ; ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdpara ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${DATADIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA}    ${WRKSRC}/example* ${EXAMPLESDIR}
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${EXAMPLESDIR}
#.if !defined(NOPORTDOCS)
#	@${MKDIR} ${DOCSDIR}
#	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${MANUALFILE} ${DOCSDIR}
#.endif

.include <bsd.port.post.mk>
