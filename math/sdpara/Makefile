# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdpara
PORTVERSION=	7.3.1
PORTREVISION=	1
CATEGORIES=	math parallel
MASTER_SITES=	SF/sdpa/sdpara
DISTNAME=	${PORTNAME}.${PORTVERSION}.src.20100914
DIST_SUBDIR=	sdpa

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDPARA parallel version of SDPA (math/sdpa)

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libblacs.so:math/blacs \
		libscalapack.so:math/scalapack \
		libmpich.so:net/mpich2

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}

USES=		fortran gmake

PORTEXAMPLES=	*
PLIST_FILES=	bin/sdpara %%DATADIR%%/param.sdpa

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_SINGLE=		BLAS
OPTIONS_SINGLE_BLAS=	ATLAS GOTOBLAS REFERENCE
OPTIONS_DEFAULT=	REFERENCE

ATLAS_USES=		blaslapack:atlas
GOTOBLAS_DESC=		GotoBLAS blas implementation
GOTOBLAS_USES=		blaslapack:gotoblas
REFERENCE_DESC=		Reference blas implementation
REFERENCE_USES=		blaslapack

LAPACK_LIBS=	-L${LOCALBASE}/lib ${LAPACKLIB}
BLAS_LIBS=	-L${LOCALBASE}/lib ${BLASLIB}
SCALAPACK_LIBS=	-L${LOCALBASE}/lib -lscalapack -lblacs -lblacsc
FORTRAN_LIBS=	${LDFLAGS} -lgfortran

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CC /s|=.*|= ${LOCALBASE}/bin/mpicc| ; \
		 /^CXX /s|=.*|= ${LOCALBASE}/bin/mpicxx| ; \
		 /^FC /s|=.*|= ${LOCALBASE}/bin/mpif77| ; \
		 /^CFLAGS /s|=.*|= ${CFLAGS}| ; \
		 /^CXXFLAGS /s|=.*|= ${CXXFLAGS}| ; \
		 /^FFLAGS /s|=.*|= ${FFLAGS}| ; \
		 /^LAPACK_LIBS /s|=.*|= ${LAPACK_LIBS}| ; \
		 /^BLAS_LIBS /s|=.*|= ${BLAS_LIBS}| ; \
		 /^SCALAPACK_LIBS /s|=.*|= ${SCALAPACK_LIBS}| ; \
		 /^FORTRAN_LIBS /s|=.*|= ${FORTRAN_LIBS}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		'/^CC /s|=.*|= ${LOCALBASE}/bin/mpicc| ; \
		 /^CFLAGS /s|=.*|= ${CFLAGS}| ; \
		 /^CXX /s|=.*|= ${LOCALBASE}/bin/mpicxx| ; \
		 /^CXXFLAGS /s|=.*|= ${CXXFLAGS}| ; \
		 /^FC /s|=.*|= ${LOCALBASE}/bin/mpif77| ; \
		 /^FFLAGS /s|=.*|= ${FFLAGS}|' \
		${WRKSRC}/mumps/Makefile

pre-build:
	@(cd ${WRKSRC}/mumps && ${DO_MAKE_BUILD} ${ALL_TARGET})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdpara ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${STAGEDIR}${DATADIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}    ${WRKSRC}/example* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
