# Created by: NAKATA Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	psi3
PORTVERSION=	3.4.0
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	SF/psicode/psi/${PORTVERSION} \
		http://www.psicode.org/doc/:doc \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|maho/psi3|}:doc

DISTNAME=	psi-${PORTVERSION}
.if !defined(NOPORTDOCS)
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} installation.pdf:doc userman.pdf:doc progman.pdf:doc
.endif
DIST_SUBDIR=	psi3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	An electronic structure programs for high-accuracy computations

.if exists(${LOCALBASE}/lib/libgoto2.so)
WITH_BLAS?=     gotoblas
.elif exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=     atlas
.else
WITH_BLAS?=	reference
.endif

. if ${WITH_BLAS} == reference
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${WITH_BLAS} == gotoblas
LIB_DEPENDS+=	goto2:${PORTSDIR}/math/gotoblas
LIB_DEPENDS+=	lapack:${PORTSDIR}/math/lapack
BLAS=		-lgoto2p
LAPACK=		-lgoto2p
.elif ${WITH_BLAS} == atlas
LIB_DEPENDS+=   atlas:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas
LAPACK=		-lalapack -lptcblas
.endif

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_FORTRAN=	yes
CONFIGURE_ARGS=	--with-cc=${CC} \
		--with-cxx=${CXX} \
		--with-fc=${FC} \
		--with-lapack="${LAPACK}" \
		--with-blas="${BLAS}" \
		--datadir=${PREFIX}/share/psi3 \
		--docdir=${WRKSRC}/tmpdoc/ \
		--with-libdirs="-L${LOCALBASE}/lib" \
		--with-libs="-lcompat"

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_FLAGS)
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double
CXXFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double  -Wno-multichar
.if (${ARCH} == "i386")
FFLAGS+=	-mfancy-math-387
CFLAGS+=	-mfancy-math-387
CXXFLAGS+=	-mfancy-math-387
.endif # i386
.endif

WRKSRC=	${WRKDIR}/${PORTNAME}
MAN1=	ccenergy.1 cceom.1 cints.1 clag.1 cscf.1 dboc.1 detcas.1 \
	detcasman.1 detci.1 geom.1 input.1 intder.1 mocube.1 mp2.1 mp2r12.1 \
	nonbonded.1 oeprop.1 optking.1 psi3.1 psiclean.1 stable.1 tocprint.1 \
	transqt.1

pre-configure:
	@${ECHO} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTREAD_CFLAGS}|g ; \
			      s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g'  ${WRKSRC}/src/bin/cints/Makefile.in
	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTREAD_CFLAGS}|g ; \
			      s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g'  ${WRKSRC}/src/bin/detci/Makefile.in

MAKE_ENV+=	SCRATCH=${WRKSRC}/tmp

do-build:
	@(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE})

do-install:
	@(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} install)
	@${TAR} cf - -C ${WRKSRC}/tmpdoc/man .  | ${TAR} xf - -C ${PREFIX}/man
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/psi3
	@${TAR} cf - -C ${WRKSRC}/tmpdoc/html . | ${TAR} xf - -C ${PREFIX}/share/doc/psi3
	@${TAR} cf - -C ${WRKSRC}/tmpdoc/txt  . | ${TAR} xf - -C ${PREFIX}/share/doc/psi3
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/installation.pdf ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/userman.pdf ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/progman.pdf ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${PREFIX}/share/examples/psi3
	@${TAR} cf - -C ${WRKSRC}/tests .       | ${TAR} xf - -C ${PREFIX}/share/examples/psi3
.endif

.include <bsd.port.post.mk>
