# New ports collection makefile for:    sdpara
# Date created:                         March 17 2003
# Whom:                                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdpara
PORTVERSION=	1.0.0
CATEGORIES=	math parallel
MASTER_SITES=   http://grid.r.dendai.ac.jp/sdpa/files/
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
		${LOCALBASE}/lib/libblacs.a:${PORTSDIR}/math/blacs \
		${LOCALBASE}/mpich/lib/libmpich.a:${PORTSDIR}/net/mpich

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
LAPACK=		-lalapack
CBLAS=		-lcblas -lf77blas -latlas -lg2c
PLIST_SUB+=     PORTVERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_FLAGS)
.if ${ARCH} == "amd64"
FFLAGS+=	-pipe -O3 -ffast-math -funroll-all-loops -fpeel-loops -ftracer -funswitch-loops -funit-at-a-time
CFLAGS+=	-pipe -O3 -ffast-math -funroll-all-loops -fpeel-loops -ftracer -funswitch-loops -funit-at-a-time
.elif ${ARCH} == "i386"
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double -mcpu=i686 -march=i686 -mfancy-math-387 -mpreferred-stack-boundary=3
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double -mcpu=i686 -march=i686 -mfancy-math-387 -mpreferred-stack-boundary=3
.else
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -Wno-multichar
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -Wno-multichar
.endif
.endif

post-patch:
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
.for i in sdpara.${PORTVERSION}.install.txt
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${i} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}

.for i in example1.dat example1.dat-s example1.ini \
	example1.ini-s example2.dat
	${INSTALL_DATA}    ${WRKSRC}/${i} ${EXAMPLESDIR}
.endfor
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${EXAMPLESDIR}

.endif

.include <bsd.port.post.mk>
