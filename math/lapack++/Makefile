# Created by: NAKATA Maho <chat95@mbox.kyoto-inet.or.jp>
# $FreeBSD$

PORTNAME=	lapack++
PORTVERSION=	2.5.3
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=   SF/lapackpp/lapackpp/${PORTVERSION} \
		http://math.nist.gov/lapack++/:doc

DISTNAME=	lapackpp-${PORTVERSION}
DIST_SUBDIR=	lapackpp
EXTRACT_ONLY=   ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Linear Algebra PACKage in C++, a wrapper for LAPACK

USES=		fortran gmake pathfix libtool

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} lapack++.ps.gz:doc lapackpp1_1.ps.gz:doc \
		lapackppman1_1.ps.gz:doc lapack++_install.ps.gz:doc
.endif

.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
.else
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas
LIB_DEPENDS+=	liblapack.so:${PORTSDIR}/math/lapack
.endif

GNU_CONFIGURE=	yes
.if defined(WITH_ATLAS)
BLAS_LIB=	-L${LOCALBASE}/lib -lf77blas
LAPACK_LIB=	-L${LOCALBASE}/lib -lalapack -lcblas
.else
BLAS_LIB=	-L${LOCALBASE}/lib -lblas
LAPACK_LIB=	-L${LOCALBASE}/lib -llapack
.endif

#BLAS_LIB=	-L${LOCALBASE}/lib -lptf77blas
#LAPACK_LIB=	-L${LOCALBASE}/lib -lalapack -lptcblas

#lapack++ forces to use atlas when detected, so we should disable here.
CONFIGURE_ARGS+=	--with-blas="${BLAS_LIB}" --with-lapack="${LAPACK_LIB}" --disable-atlas --enable-static

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapack++.ps.gz ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapack++_install.ps.gz ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapackpp1_1.ps.gz ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapackppman1_1.ps.gz ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
