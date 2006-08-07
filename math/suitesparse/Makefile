# New ports collection makefile for:	ufspace
# Date created:		4 July 2006
# Whom:			Maho Nakata <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ufsparse
PORTVERSION=	2.0.0.b
CATEGORIES=	math
MASTER_SITES=	http://www.cise.ufl.edu/research/sparse/UFsparse/v2.0.0beta/
DISTNAME=	UFsparse

MAINTAINER=	maho@FreeBSD.org
COMMENT=	UFspace is a set of packages for sparse matrices calculation

BUILD_DEPENDS=  ${LOCALBASE}/lib/libmetis.a:${PORTSDIR}/math/metis

.if defined(WITH_BLAS)
LIB_DEPENDS+=	blas.1:${PORTSDIR}/math/blas
BLAS=	-L${LOCALBASE}/lib -lblas
LAPACK=	-L${LOCALBASE}/lib -llapack
.else
LIB_DEPENDS+=	atlas.1:${PORTSDIR}/math/atlas
BLAS=	-L${LOCALBASE}/lib -lf77blas -latlas -lg2c
LAPACK=	-L${LOCALBASE}/lib -lalapack -lcblas
.endif

USE_GMAKE=	yes
ALL_TARGET=

post-patch:
	@${REINPLACE_CMD} -e 's,%%CC%%,${CC},g' \
			  -e 's,%%CFLAGS%%,${CFLAGS},g' \
			  -e 's,%%F77%%,${FC},g' \
			  -e 's,%%FFLAGS%%,${FFLAGS},g' \
			  -e 's,%%BLAS%%,${BLAS},g' \
			  -e 's,%%LAPACK%%,${LAPACK},g' \
				 ${WRKSRC}/UFconfig/UFconfig.mk
do-install:
	${MKDIR} ${PREFIX}/include/ufsparse
	${INSTALL_DATA} ${WRKDIR}/UFsparse/UFconfig/UFconfig.h                       ${PREFIX}/include/ufsparse
	${INSTALL_DATA} ${WRKDIR}/UFsparse/UMFPACK/Include/*.h                       ${PREFIX}/include/ufsparse
	${INSTALL_DATA} ${WRKDIR}/UFsparse/AMD/Include/*.h			     ${PREFIX}/include/ufsparse
	${INSTALL_DATA} ${WRKDIR}/UFsparse/BTF/Include/*.h			     ${PREFIX}/include/ufsparse
	${INSTALL_DATA} ${WRKDIR}/UFsparse/CCOLAMD/*.h   	                     ${PREFIX}/include/ufsparse
	${INSTALL_DATA} ${WRKDIR}/UFsparse/CHOLMOD/Include/*.h                 	     ${PREFIX}/include/ufsparse
	${INSTALL_DATA} ${WRKDIR}/UFsparse/COLAMD/*.h    	                     ${PREFIX}/include/ufsparse
	${INSTALL_DATA} ${WRKDIR}/UFsparse/CXSparse/Source/*.h 	                     ${PREFIX}/include/ufsparse
	${INSTALL_DATA} ${WRKDIR}/UFsparse/KLU/Include/*.h                           ${PREFIX}/include/ufsparse
	${INSTALL_DATA} ${WRKDIR}/UFsparse/CAMD/Include/*.h		             ${PREFIX}/include/ufsparse
	${INSTALL_DATA} ${WRKDIR}/UFsparse/UMFPACK/Lib/libumfpack.a                  ${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/UFsparse/AMD/Lib/libamd.a                          ${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/UFsparse/CCOLAMD/libccolamd.a                      ${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/UFsparse/CHOLMOD/Lib/libcholmod.a                  ${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/UFsparse/COLAMD/libcolamd.a                        ${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/UFsparse/KLU/Lib/libklu.a                          ${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/UFsparse/BTF/Lib/libbtf.a                          ${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/UFsparse/CAMD/Lib/libcamd.a                        ${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/UFsparse/CXSparse/Source/libcxsparse.a             ${PREFIX}/lib

.include <bsd.port.mk>
