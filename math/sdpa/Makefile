# New ports collection makefile for:    sdpa
# Date created:                         October 4 2003
# Whom:                                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdpa
PORTVERSION=	6.00
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://grid.r.dendai.ac.jp/sdpa/
DISTFILES=	${PORTNAME}.${PORTVERSION}.src.tar.gz
.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}.${PORTVERSION}.manual.ps.gz \
		${PORTNAME}.${PORTVERSION}.manual.pdf \
		${PORTNAME}.${PORTVERSION}.install.txt
.endif
DIST_SUBDIR=	sdpa
EXTRACT_ONLY=	${PORTNAME}.${PORTVERSION}.src.tar.gz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SDPA(SemiDefinite Programming Algorithm) Very efficent SDP Solver

.if defined(USE_ICC)
BUILD_DEPENDS=	${LOCALBASE}/intel_cc_80/bin/icc:${PORTSDIR}/lang/icc
.endif
LIB_DEPENDS=	atlas:${PORTSDIR}/math/atlas

RESTRICTED=	"unsure distribution condition"

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
LAPACK=		-lalapack
CBLAS=		-lcblas -lf77blas -latlas -lg2c
#USE_ICC=	yes

.if defined(WITH_OPTIMIZED_FLAGS)
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double
CXXFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double  -Wno-multichar
.if (${MACHINE_ARCH} == "i386")
CFLAGS+=	-mcpu=i686 -march=i686 -mfancy-math-387 -mpreferred-stack-boundary=3
CXXFLAGS+=	-mcpu=i686 -march=i686 -mfancy-math-387 -mpreferred-stack-boundary=3
.endif # i386
.endif

.if defined(USE_ICC)
CC=		${LOCALBASE}/intel_cc_80/bin/icc
CXX=		${LOCALBASE}/intel_cc_80/bin/icpc
CFLAGS=		-O3 -tpp7 -xiMKW -Vaxlib
CXXFLAGS=	-O3 -tpp7 -xiMKW -Vaxlib
.endif

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKDIR}
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
			      s|%%LAPACK%%|${LAPACK}|g ; \
			      s|%%LOCALBASE%%|${LOCALBASE}|g ; \
			      s|%%CBLAS%%|${CBLAS}|g'  ${WRKDIR}/Makefile
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
			      s|%%LOCALBASE%%|${LOCALBASE}|g ; \
			      s|%%CXX%%|${CXX}| g ; \
			      s|%%CXXFLAGS%%|${CXXFLAGS}|g ; \
			      s|%%LAPACK%%|${LAPACK}|g ; \
			      s|%%CBLAS%%|${CBLAS}|g'  ${WRKSRC}/Makefile
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
.for i in sdpa.6.00.manual.ps.gz sdpa.6.00.manual.pdf sdpa.6.00.install.txt
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

.include <bsd.port.mk>
