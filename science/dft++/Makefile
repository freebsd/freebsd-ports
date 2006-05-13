# New ports collection makefile for:   dft++
# Date Created:                18 March 2004
# Whom:                        NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dft++
PORTVERSION=	3.0
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

LIB_DEPENDS=	atlas:${PORTSDIR}/math/atlas\
		fftw.2:${PORTSDIR}/math/fftw

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes
LAPACK=		-lalapack -lcblas -lf77blas -lg2c -latlas
FFTW=		-lfftw

.if defined(WITH_OPTIMIZED_FLAGS)
OPTIMIZED_FLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double
.if (${MACHINE_ARCH} == "i386")
OPTIMIZED_FLAGS+=	-mcpu=i686 -march=i686 -mfancy-math-387 -mpreferred-stack-boundary=3
.endif # i386
.endif

pre-patch:
	${CP} ${WRKSRC}/makefile ${WRKSRC}/makefile-pw
	${CP} ${WRKSRC}/makefile ${WRKSRC}/makefile-wl

pre-configure:
	@${ECHO} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
	@${REINPLACE_CMD} -e ' s|%%FC%%|${FC}|g ; \
			      s|%%CC%%|${CC}|g ; \
			      s|%%CXX%%|${CXX}|g ; \
			      s|%%OPTIMIZED_FLAGS%%|${OPTIMIZED_FLAGS}|g ; \
			      s|%%LAPACK%%|${LAPACK}|g ; \
			      s|%%FFTW%%|${FFTW}|g ; \
			      s|%%LOCALBASE%%|${LOCALBASE}|g ; \
			      s|%%FFLAGS%%|${FFLAGS}|g ; \
			      s|%%CFLAGS%%|${CFLAGS}|g ; \
			      s|%%CXXFLAGS%%|${CXXFLAGS}|g ;' ${WRKSRC}/makefile.local-pw
	@${REINPLACE_CMD} -e ' s|%%FC%%|${FC}|g ; \
			      s|%%CC%%|${CC}|g ; \
			      s|%%CXX%%|${CXX}|g ; \
			      s|%%LAPACK%%|${LAPACK}|g ; \
			      s|%%FFTW%%|${FFTW}|g ; \
			      s|%%OPTIMIZED_FLAGS%%|${OPTIMIZED_FLAGS}|g ; \
			      s|%%FFLAGS%%|${FFLAGS}|g ; \
			      s|%%CFLAGS%%|${CFLAGS}|g ; \
			      s|%%LOCALBASE%%|${LOCALBASE}|g ; \
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

.include <bsd.port.mk>
