# New ports collection makefile for:	ProjectionLib library from VTP
# Date created:				26 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	projectionlib
PORTVERSION=	3.7
CATEGORIES=	misc
MASTER_SITES=	http://thor-f5.er.usgs.gov/viewers/dlgv32/
DISTNAME=	dlgv32v37src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ wrapper for the USGS GCTP projection library

LIB_DEPENDS=	gctpc.1:${PORTSDIR}/misc/gctpc

EXTRACT_CMD=	unzip -a

WRKSRC=		${WRKDIR}/dlgv32/ProjectionLib

USE_ZIP=	yes
INSTALLS_SHLIB=	yes
MAKEFILE=	${FILESDIR}/Makefile

post-install:
	${MKDIR} ${PREFIX}/include/ProjectionLib
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/ProjectionLib

.include <bsd.port.mk>
