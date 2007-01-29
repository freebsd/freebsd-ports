# New ports collection makefile for:   dft++
# Date Created:                18 March 2004
# Whom:                        NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dft++
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://dft.physics.cornell.edu/src/ \
		http://dft.physics.cornell.edu/example/:example
DISTFILES=	${PORTNAME}.v${PORTVERSION}.tar.gz
.if !defined(NOPORTDOCS)
DISTFILES+=	dft.in:example si_psp.tar:example output:example
.endif
DIST_SUBDIR=	dft++
EXTRACT_ONLY=	${PORTNAME}.v${PORTVERSION}.tar.gz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	DFT++, A density functional software

.include <bsd.port.pre.mk>

LIB_DEPENDS+=	fftw.2:${PORTSDIR}/math/fftw
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes
WANT_FORTRAN=yes #dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=	gfortran42
F77=	gfortran42
FORTRANLIBS=    -lgfortranbegin -lgfortran
GCCLIBDIR=	-L`${CAT} ${WRKSRC}/LIBDIR` -L`${CAT} ${WRKSRC}/LIBDIR`/../../..

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=     yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=   atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas -lcblas
LAPACK=		-lalapack
.else
LIB_DEPENDS+=   blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=   lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif
FFTW=		-lfftw

.if defined(WITH_OPTIMIZED_FLAGS)
OPTIMIZED_FLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double
.if (${ARCH} == "i386")
OPTIMIZED_FLAGS+=	-mcpu=i686 -march=i686 -mfancy-math-387 -mpreferred-stack-boundary=3
.endif # i386
.endif

pre-patch:
	${CP} ${WRKSRC}/makefile ${WRKSRC}/makefile-pw
	${CP} ${WRKSRC}/makefile ${WRKSRC}/makefile-wl

pre-configure:
	@${DIRNAME} `${F77} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
	@${ECHO} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
	@${REINPLACE_CMD} -e ' s|%%FC%%|${FC}|g ; \
			      s|%%CC%%|${CC}|g ; \
			      s|%%CXX%%|${CXX}|g ; \
			      s|%%OPTIMIZED_FLAGS%%|${OPTIMIZED_FLAGS}|g ; \
			      s|%%LAPACK%%|${LAPACK}|g ; \
			      s|%%BLAS%%|${BLAS}|g ; \
			      s|%%FFTW%%|${FFTW}|g ; \
			      s|%%LOCALBASE%%|${LOCALBASE}|g ; \
			      s|%%FFLAGS%%|${FFLAGS}|g ; \
			      s|%%CFLAGS%%|${CFLAGS}|g ; \
			      s|%%FORTRANLIBS%%|${FORTRANLIBS} ${GCCLIBDIR}|g ; \
			      s|%%CXXFLAGS%%|${CXXFLAGS}|g ;' ${WRKSRC}/makefile.local-pw
	@${REINPLACE_CMD} -e ' s|%%FC%%|${FC}|g ; \
			      s|%%CC%%|${CC}|g ; \
			      s|%%CXX%%|${CXX}|g ; \
			      s|%%BLAS%%|${BLAS}|g ; \
			      s|%%LAPACK%%|${LAPACK}|g ; \
			      s|%%FFTW%%|${FFTW}|g ; \
			      s|%%OPTIMIZED_FLAGS%%|${OPTIMIZED_FLAGS}|g ; \
			      s|%%FFLAGS%%|${FFLAGS}|g ; \
			      s|%%CFLAGS%%|${CFLAGS}|g ; \
			      s|%%LOCALBASE%%|${LOCALBASE}|g ; \
			      s|%%FORTRANLIBS%%|${FORTRANLIBS} ${GCCLIBDIR}|g ; \
			      s|%%CXXFLAGS%%|${CXXFLAGS}|g ;' ${WRKSRC}/makefile.local-wl

do-build:
	@cd ${WRKSRC} ; ${GMAKE}	-f makefile-pw dft-pw
	@cd ${WRKSRC} ; ${GMAKE}	-f makefile-pw clean
	@cd ${WRKSRC} ; ${GMAKE}	-f makefile-wl dft-wl

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dft-pw ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/dft-wl ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/dft.in     ${EXAMPLESDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/output     ${EXAMPLESDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/si_psp.tar ${EXAMPLESDIR}
	@${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/si_psp.tar -C    ${EXAMPLESDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
