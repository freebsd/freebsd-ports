# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdpara
PORTVERSION=	7.2.1
PORTREVISION=	7
CATEGORIES=	math parallel
MASTER_SITES=	http://sdpa.indsys.chuo-u.ac.jp/sdpa/files/
DISTFILES=	${SRCFILE}#${MANUALFILE}
DIST_SUBDIR=	sdpa
EXTRACT_ONLY=	${SRCFILE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDPARA parallel version of SDPA (math/sdpa)

LIB_DEPENDS=	libscalapack.so:${PORTSDIR}/math/scalapack \
		libblacs.so:${PORTSDIR}/math/blacs \
		libmpich.so:${PORTSDIR}/net/mpich2

SRCDATE=	20090109
MANDATE=	20080618
MANUALVER=	7.1.1
SRCFILE=	${PORTNAME}.${PORTVERSION}.src.${SRCDATE}.tar.gz
#MANUALFILE=	${PORTNAME}.${MANUALVER}.manual.${MANDATE}.pdf
USES=		fortran gmake
WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}

.if exists(${LOCALBASE}/lib/libgoto2.so)
WITH_BLAS?=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

. if ${WITH_BLAS} == reference
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas
LIB_DEPENDS+=	liblapack.so:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${WITH_BLAS} == gotoblas
LIB_DEPENDS+=	libgoto2.so:${PORTSDIR}/math/gotoblas
BLAS=		-lgoto2p
LAPACK=		-lgoto2p
.elif ${WITH_BLAS} == atlas
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas
LAPACK=		-lalapack -lptcblas
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
	cd ${WRKSRC} ; ${MAKE_CMD} mumps
	cd ${WRKSRC} ; ${MAKE_CMD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdpara ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}    ${WRKSRC}/example* ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${STAGEDIR}${EXAMPLESDIR}
#	@${MKDIR} ${STAGEDIR}${DOCSDIR}
#	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${MANUALFILE} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
