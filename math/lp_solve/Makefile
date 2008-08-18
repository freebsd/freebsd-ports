# New ports collection makefile for:	lp_solve
# Date created:         31 June 2003
# Whom:			Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	lp_solve
PORTVERSION=	5.5.0.13
CATEGORIES=	math
MASTER_SITES=	SF/lpsolve
DISTNAME=	${PORTNAME}_${PORTVERSION}_source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linear Programming Solver

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:R:R}

USE_LDCONFIG=	yes

post-patch:
	@${FIND} ${WRKSRC} -name "ccc" | ${XARGS} ${REINPLACE_CMD} -e \
		"s|^c=.*$$|c='${CC}'|g ; \
		 s|^opts=.*$$|opts='${CFLAGS}'|g ; \
		 s|-fpic|-fPIC|g ; \
		 s|-ldl||g"

do-build:
	cd ${WRKSRC}/lp_solve  ; ${SH} -x ccc
	cd ${WRKSRC}/demo      ; ${SH} -x ccc
	cd ${WRKSRC}/lpsolve55 ; ${SH} -x ccc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lp_solve/lp_solve ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/include/lpsolve
.for i in lp_Hash.h lp_SOS.h lp_lib.h lp_matrix.h lp_mipbb.h lp_types.h lp_utils.h 
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/include/lpsolve
.endfor
.for i in lpsolve55/liblpsolve55.a lpsolve55/liblpsolve55.so
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/lib
.endfor
	${LN} -sf liblpsolve55.so ${PREFIX}/lib/liblpsolve55.so.1

.include <bsd.port.mk>
