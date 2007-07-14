# New ports collection makefile for:    sdpa
# Date created:                         October 4 2003
# Whom:                                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdpa
PORTVERSION=	6.2.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://sdpa.indsys.chuo-u.ac.jp/sdpa/files/
DISTFILES=	${PORTNAME}.${PORTVERSION}.src.tar.gz
.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}.${OLDVERSION}.manual.ps.gz \
		${PORTNAME}.${OLDVERSION}.manual.pdf \
		${PORTNAME}.${OLDVERSION}.install.txt
.endif
DIST_SUBDIR=	sdpa
EXTRACT_ONLY=	${PORTNAME}.${PORTVERSION}.src.tar.gz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SDPA(SemiDefinite Programming Algorithm) Very efficent SDP Solver

.if defined(WITH_ICC)
BUILD_DEPENDS+=	${LOCALBASE}/intel_cc_80/bin/icc:${PORTSDIR}/lang/icc
.endif

USE_FORTRAN=	yes
OLDVERSION=	6.2.0
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

#for f2c.h
BUILD_DEPENDS+=	${LOCALBASE}/lib/libf2c.a:${PORTSDIR}/lang/f2c

.include <bsd.port.pre.mk>

#always needs atlas for lapack.h and blas.h
#.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
#.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lcblas -lf77blas -latlas
LAPACK=		-lalapack
CXXFLAGS+=	-DNON_ATLAS_SDPA=0
.else
LIB_DEPENDS+=   blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=   lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
CXXFLAGS+=	-DNON_ATLAS_SDPA=1
.endif
FORTRANLIBS=	-lgfortranbegin -lgfortran
GCCLIBDIR=	-L`${CAT} ${WRKSRC}/LIBDIR` -L`${CAT} ${WRKSRC}/LIBDIR`/../../..

PLIST_SUB+=     PORTVERSION="${PORTVERSION}"
#WITH_SMP=	yes
#WITH_ICC=	yes

.if defined(WITH_OPTIMIZED_FLAGS)
.if ${ARCH} == "amd64"
CFLAGS+=	-pipe -O3 -ffast-math -funroll-all-loops -fpeel-loops -ftracer -funswitch-loops -funit-at-a-time
CXXFLAGS+=	-pipe -O3 -ffast-math -funroll-all-loops -fpeel-loops -ftracer -funswitch-loops -funit-at-a-time
.elif ${ARCH} == "i386"
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double -mcpu=i686 -march=i686 -mfancy-math-387 -mpreferred-stack-boundary=3
CXXFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -Wno-multichar -malign-double -mcpu=i686 -march=i686 -mfancy-math-387 -mpreferred-stack-boundary=3
.else
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations
CXXFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -Wno-multichar
.endif
.endif

.if defined(WITH_ICC)
CC=		${LOCALBASE}/intel_cc_80/bin/icc
CXX=		${LOCALBASE}/intel_cc_80/bin/icpc
CFLAGS=		-O3 -tpp7 -axN -Vaxlib
CXXFLAGS=	-O3 -tpp7 -axN -Vaxlib
.endif

pre-build:
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}
	@${DIRNAME} `${FC} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
			      s|%%LOCALBASE%%|${LOCALBASE}|g ; \
			      s|%%LAPACK%%|${LAPACK}|g ; \
			      s|%%BLAS%%|${BLAS}|g ; \
			      s|%%FORTRANLIBS%%|${FORTRANLIBS}|g ; \
			      s|%%GCCLIBDIR%%|${GCCLIBDIR}|g'  ${WRKDIR}/Makefile
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
			      s|%%LOCALBASE%%|${LOCALBASE}|g ; \
			      s|%%CXX%%|${CXX}| g ; \
			      s|%%CXXFLAGS%%|${CXXFLAGS}|g ; \
			      s|%%LAPACK%%|${LAPACK}|g ; \
			      s|%%BLAS%%|${BLAS}|g ; \
			      s|%%FORTRANLIBS%%|${FORTRANLIBS}|g ; \
			      s|%%GCCLIBDIR%%|${GCCLIBDIR}|g' ${WRKSRC}/Makefile

.if !defined(WITH_OPTIMIZED_FLAGS)
	@${ECHO} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdpa ${PREFIX}/bin
	${INSTALL_DATA}    ${WRKSRC}/libsdpa.a ${PREFIX}/lib
	${INSTALL_DATA}    ${WRKSRC}/sdpa-lib.hpp ${PREFIX}/include
	${INSTALL_DATA}    ${WRKSRC}/sdpa-lib2.hpp  ${PREFIX}/include
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTNAME}.${OLDVERSION}.manual.ps.gz ${PORTNAME}.${OLDVERSION}.manual.pdf ${PORTNAME}.${OLDVERSION}.install.txt
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${i} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for i in example1-1.cpp example1-2.cpp example1.dat example1.dat-s example1.ini \
	example1.ini-s example1.result example2-1.cpp example2-2.cpp \
	example2.dat example2.result example3.cpp example4.cpp \
	example5.cpp example6.cpp
	${INSTALL_DATA}    ${WRKSRC}/${i} ${EXAMPLESDIR}
.endfor
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${EXAMPLESDIR}
	${INSTALL_DATA}    ${WRKDIR}/Makefile ${EXAMPLESDIR}

.endif

.include <bsd.port.post.mk>
