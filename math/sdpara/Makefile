# New ports collection makefile for:    sdpara
# Date created:                         March 17 2003
# Whom:                                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdpara
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	math parallel
MASTER_SITES=   http://sdpa.indsys.chuo-u.ac.jp/sdpa/files/
DISTFILES=	${PORTNAME}.${PORTVERSION}.src.tar.gz
.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}.1.0.0.install.txt
.endif
DIST_SUBDIR=	sdpara
EXTRACT_ONLY=	${PORTNAME}.${PORTVERSION}.src.tar.gz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SDPARA paralell version of SDPA (math/sdpa)

LIB_DEPENDS=	atlas:${PORTSDIR}/math/atlas \
		scalapack:${PORTSDIR}/math/scalapack \
		blacs:${PORTSDIR}/math/blacs \
		mpich:${PORTSDIR}/net/mpich2

USE_FORTRAN=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

#Atlas is always required as lapack.h and blas.h is required.
#no blaswarp.h at the moment.
LIB_DEPENDS+=   atlas.2:${PORTSDIR}/math/atlas
WITH_ATLAS=     yes
.if defined(WITH_ATLAS)
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

pre-build:
	${DIRNAME} `${F77} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
			      s|%%LOCALBASE%%|${LOCALBASE}|g ; \
			      s|%%CXXFLAGS%%|${CXXFLAGS}|g ; \
			      s|%%FFLAGS%%|${FFLAGS}|g ; \
			      s|%%LAPACK%%|${LAPACK}|g ; \
			      s|%%BLAS%%|${BLAS}|g ; \
			      s|%%GCCLIBDIR%%|${GCCLIBDIR}|g ; \
			      s|%%FORTRANLIBS%%|${FORTRANLIBS}|g '  ${WRKSRC}/Makefile
.if !defined(WITH_OPTIMIZED_FLAGS)
	@${ECHO} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdpara ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in sdpara.1.0.0.install.txt
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
