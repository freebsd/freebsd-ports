# New ports collection makefile for:	SuperLU
# Version required:	2.0
# Date created:		31 Oct 97
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

DISTNAME=	superlu_2.0
PKGNAME=	superlu-2.0
CATEGORIES=	math
MASTER_SITES=	http://www.nersc.gov/~xiaoye/SuperLU/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libblas.a:${PORTSDIR}/math/blas

WRKSRC=		${WRKDIR}/SuperLU
ALL_TARGET=	superlulib
#
#	NOTE:	The Matlab interface was not built.
#

do-install:
	${INSTALL_DATA} ${WRKSRC}/libsuperlu.* ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/SRC/supermatrix.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/SuperLU
	${INSTALL_DATA} ${WRKSRC}/INSTALL/*.ps ${PREFIX}/share/doc/SuperLU
.endif

.include <bsd.port.mk>
