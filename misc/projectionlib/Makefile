# New ports collection makefile for:	ProjectionLib library from VTP
# Date created:				26 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	projectionlib
PORTVERSION=	3.7
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftpmcmc.er.usgs.gov/release/viewers/dlgv32/source/
DISTNAME=	Dlgv32v37

MAINTAINER=	ports@FreeBSD.org

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
