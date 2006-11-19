# New ports collection makefile for:	ufspace
# Date created:		4 July 2006
# Whom:			Maho Nakata <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	suitesparse
PORTVERSION=	2.1.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.cise.ufl.edu/research/sparse/SuiteSparse/current/
DISTNAME=	SuiteSparse
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SuiteSparse is a set of packages for sparse matrices calculation

CONFLICTS=	elmer-umfpack-4*

BUILD_DEPENDS=  ${LOCALBASE}/lib/libmetis.a:${PORTSDIR}/math/metis

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "amd64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif

CFLAGS+=	${FPIC}
FFLAGS+=	${FPIC}

.if defined(WITH_BLAS)
LIB_DEPENDS+=	blas.1:${PORTSDIR}/math/blas
BLAS=	-L${LOCALBASE}/lib -lblas
LAPACK=	-L${LOCALBASE}/lib -llapack
.else
LIB_DEPENDS+=	atlas.1:${PORTSDIR}/math/atlas
BLAS=	-L${LOCALBASE}/lib -lf77blas -latlas -lg2c
LAPACK=	-L${LOCALBASE}/lib -lalapack -lcblas
.endif

CONFLICTS=	umfpack-*

ALL_TARGET=	default
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,%%CC%%,${CC},g' \
			  -e 's,%%CFLAGS%%,${CFLAGS},g' \
			  -e 's,%%F77%%,${FC},g' \
			  -e 's,%%FFLAGS%%,${FFLAGS},g' \
			  -e 's,%%BLAS%%,${BLAS},g' \
			  -e 's,%%LAPACK%%,${LAPACK},g' \
			  -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
				 ${WRKSRC}/UFconfig/UFconfig.mk
	@${REINPLACE_CMD} -e 's,%%CC%%,${CC},g' \
			  -e 's,%%CFLAGS%%,${CFLAGS},g' \
				${WRKSRC}/CSparse/Source/Makefile \
				${WRKSRC}/CXSparse/Source/Makefile
do-install:			 
	${MKDIR} ${PREFIX}/include/suitesparse
	${LN} -sf ${PREFIX}/include/suitesparse ${PREFIX}/include/ufsparse
	${INSTALL_DATA} ${WRKSRC}/UFconfig/UFconfig.h                       ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/UMFPACK/Include/*.h                       ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/AMD/Include/*.h			     ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/BTF/Include/*.h			     ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/CCOLAMD/*.h   	                     ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/CHOLMOD/Include/*.h                 	     ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/COLAMD/*.h    	                     ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/CXSparse/Source/*.h 	                     ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/KLU/Include/*.h                           ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/CAMD/Include/*.h		             ${PREFIX}/include/suitesparse
	${INSTALL_DATA} ${WRKSRC}/UMFPACK/Lib/libumfpack.a                  ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/AMD/Lib/libamd.a                          ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/CCOLAMD/libccolamd.a                      ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/CHOLMOD/Lib/libcholmod.a                  ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/COLAMD/libcolamd.a                        ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/KLU/Lib/libklu.a                          ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/BTF/Lib/libbtf.a                          ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/CAMD/Lib/libcamd.a                        ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/CXSparse/Source/libcxsparse.a             ${PREFIX}/lib

.include <bsd.port.post.mk>
