# New ports collection makefile for:	psi3
# Date created:				March 17 2004
# Whom:					NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	psi3
PORTVERSION=	3.2.1
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.psicode.org/doc/:doc
#		http://www.psicode.org/downloads.php
MASTER_SITE_SUBDIR=	maho/psi3
DISTNAME=	psi-${PORTVERSION}
.if !defined(NOPORTDOCS)
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} installation.pdf:doc userman.pdf:doc progman.pdf:doc
.endif
DIST_SUBDIR=	psi3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	An electronic structure programs for high-accuracy computations

LIB_DEPENDS=	atlas:${PORTSDIR}/math/atlas

BROKEN=		Size mismatch

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_AUTOCONF_VER=259

CONFIGURE_ARGS=	--with-cc=${CC} \
		--with-cxx=${CXX} \
		--with-fc=${FC} \
		--with-lapack="-lalapack -lcblas" \
		--with-blas="-lf77blas -latlas" \
		--datadir=${PREFIX}/share/psi3 \
		--with-libdirs="-L${LOCALBASE}/lib" \
		--with-libs="-lcompat"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

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
	detcasman.1 detci.1 geom.1 input.1 mocube.1 mp2.1 mp2r12.1 \
	oeprop.1 optking.1 psi3.1 psiclean.1 stable.1 tocprint.1 transqt.1
pre-configure:
	@${ECHO} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
	@${REINPLACE_CMD} -e 's|%%TMPDOC%%|${WRKSRC}/tmpdoc|g ; \
			      s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g ; \
			      s|%%FFLAGS%%|${FFLAGS}|g ; \
			      s|%%CFLAGS%%|${CFLAGS}|g ; \
			      s|%%CXXFLAGS%%|${CXXFLAGS}|g ;' ${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTREAD_CFLAGS}|g ; \
			      s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g'  ${WRKSRC}/src/bin/cints/Makefile.in
	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTREAD_CFLAGS}|g ; \
			      s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g'  ${WRKSRC}/src/bin/detci/Makefile.in

MAKE_ENV+=	SCRATCH=${WRKSRC}/tmp

do-build:
	@(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE})

do-install:
	@(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} install)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/psi3
	@${TAR} cf - -C ${WRKSRC}/tmpdoc/man .  | ${TAR} xf - -C ${PREFIX}/man
	@${TAR} cf - -C ${WRKSRC}/tmpdoc/html . | ${TAR} xf - -C ${PREFIX}/share/doc/psi3
	@${TAR} cf - -C ${WRKSRC}/tmpdoc/txt  . | ${TAR} xf - -C ${PREFIX}/share/doc/psi3
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/installation.pdf ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/userman.pdf ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/progman.pdf ${DOCSDIR}
.endif
	@${MKDIR} ${PREFIX}/share/examples/psi3
	@${TAR} cf - -C ${WRKSRC}/tests .       | ${TAR} xf - -C ${PREFIX}/share/examples/psi3

.include <bsd.port.post.mk>
