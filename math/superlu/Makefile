# New ports collection makefile for:	SuperLU
# Date created:		31 Oct 97
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	superlu
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.nersc.gov/~xiaoye/SuperLU/
DISTNAME=	${PORTNAME}_${PORTVERSION}

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
