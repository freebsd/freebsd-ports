# New ports collection makefile for:	lp_solve
# Date created:         31 June 2003
# Whom:			Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	lp_solve
PORTVERSION=	${PORTMAJOR_VER}.0.9
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} # http://groups.yahoo.com/group/lp_solve/
MASTER_SITE_SUBDIR=	lpsolve
DISTNAME=	${PORTNAME}_${PORTVERSION}_source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linear Programming Solver

PORTMAJOR_VER=	5.5
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTMAJOR_VER}
INSTALLS_SHLIB=	yes

.if ${MACHINE_ARCH} == "sparc64"
PICFLAG?=       -fPIC
.else
PICFLAG?=       -fpic
.endif

pre-build:
	@${REINPLACE_CMD} -e 's:%%CFLAGS%%:${CFLAGS}:g' -e 's:%%PICFLAG%%:${PICFLAG}:g'  -e 's:%%CC%%:${CC}:g' ${WRKSRC}/lp_solve/ccc ${WRKSRC}/demo/ccc ${WRKSRC}/lpsolve55/ccc

do-build:
	cd ${WRKSRC}/lp_solve  ; ${SH} -x ccc
	cd ${WRKSRC}/demo      ; ${SH} -x ccc
	cd ${WRKSRC}/lpsolve55 ; ${SH} -x ccc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lp_solve/lp_solve ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/demo/demo ${EXAMPLESDIR}
	${MKDIR} ${PREFIX}/include/lpsolve
	${INSTALL_DATA} ${WRKSRC}/lp_lib.h ${PREFIX}/include/lpsolve
	${INSTALL_DATA} ${WRKSRC}/lp_types.h ${PREFIX}/include/lpsolve
	${INSTALL_DATA} ${WRKSRC}/lp_utils.h ${PREFIX}/include/lpsolve
	${INSTALL_DATA} ${WRKSRC}/lp_Hash.h ${PREFIX}/include/lpsolve
	${INSTALL_DATA} ${WRKSRC}/lp_matrix.h ${PREFIX}/include/lpsolve
	${INSTALL_DATA} ${WRKSRC}/lp_mipbb.h ${PREFIX}/include/lpsolve
	${INSTALL_DATA} ${WRKSRC}/lp_SOS.h ${PREFIX}/include/lpsolve
	${INSTALL_DATA} ${WRKSRC}/lpsolve55/liblpsolve55.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lpsolve55/liblpsolve55.so ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/liblpsolve55.so ${PREFIX}/lib/liblpsolve55.so.1

.include <bsd.port.mk>
