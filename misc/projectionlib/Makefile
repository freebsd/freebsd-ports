# Created by: Randall Hopper <aa8vb@nc.rr.com>
# $FreeBSD$

PORTNAME=	projectionlib
PORTVERSION=	3.7
CATEGORIES=	misc
MASTER_SITES=	http://thor-f5.er.usgs.gov/viewers/dlgv32/
DISTNAME=	dlgv32v37src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ wrapper for the USGS GCTP projection library

LIB_DEPENDS=	gctpc.1:${PORTSDIR}/misc/gctpc

WRKSRC=		${WRKDIR}/dlgv32/ProjectionLib

USE_ZIP=	yes
USE_DOS2UNIX=	*.cpp *.h
USE_LDCONFIG=	yes
MAKEFILE=	${FILESDIR}/Makefile

NO_STAGE=	yes
post-install:
	${MKDIR} ${PREFIX}/include/ProjectionLib
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/ProjectionLib

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		does not patch
.endif

.include <bsd.port.post.mk>
