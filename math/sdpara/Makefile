# New ports collection makefile for:    sdpara
# Date created:                         March 17 2003
# Whom:                                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdpara
PORTVERSION=	0.90
CATEGORIES=	math parallel
MASTER_SITES=	http://sdpa.is.titech.ac.jp/
DISTFILES=	${PORTNAME}.${PORTVERSION}.src.tar.gz
.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}.${PORTVERSION}.install.txt
.endif
DIST_SUBDIR=	sdpara
EXTRACT_ONLY=	${PORTNAME}.${PORTVERSION}.src.tar.gz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SDPARA paralell version of SDPA (math/sdpa)

LIB_DEPENDS=	atlas:${PORTSDIR}/math/atlas
BUILD_DEPENDS=	${LOCALBASE}/lib/libscalapack.a:${PORTSDIR}/math/scalapack \
		${LOCALBASE}/mpich/lib/libmpich.a:${PORTSDIR}/net/mpich

RESTRICTED=	"unsure distribution condition"

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
LAPACK=		-lalapack
CBLAS=		-lcblas -lf77blas -latlas -lg2c

.if defined(WITH_OPTIMIZED_FLAGS)
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double
CXXFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double  -Wno-multichar
.if (${ARCH} == "i386")
FFLAGS+=	-mfancy-math-387 -mpreferred-stack-boundary=3
CXXFLAGS+=	-mfancy-math-387 -mpreferred-stack-boundary=3
.endif # i386
.endif

pre-build:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
			      s|%%LOCALBASE%%|${LOCALBASE}|g ; \
			      s|%%CXXFLAGS%%|${CXXFLAGS}|g ; \
			      s|%%FFLAGS%%|${FFLAGS}|g ; \
			      s|%%LAPACK%%|${LAPACK}|g ; \
			      s|%%CBLAS%%|${CBLAS}|g'  ${WRKSRC}/Makefile
.if !defined(WITH_OPTIMIZED_FLAGS)
	@${ECHO} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdpara ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in sdpara.0.90.install.txt
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${i} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}

.for i in example1.dat example1.dat-s example1.ini \
	example1.ini-s example2.dat
	${INSTALL_DATA}    ${WRKSRC}/${i} ${EXAMPLESDIR}
.endfor
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${EXAMPLESDIR}

.endif

.include <bsd.port.mk>
