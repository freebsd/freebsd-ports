# New ports collection makefile for:   xps
# Date created:        4 December 2008
# Whom:                antonakis@gmail.com
#
# $FreeBSD$

PORTNAME=	xps
PORTVERSION=	0.4
CATEGORIES=	ports-mgmt
MASTER_SITES=	https://github.com/antanst/xps/archive/
DISTFILES=	v0.4.tar.gz
FETCH_ARGS=	-Fpr
  
MAINTAINER=	anastasiadis@datalive.gr
COMMENT=	A tool that searches the ports tree by various criteria

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/xps

MAN1=	xps.1

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/xps.1 ${PREFIX}/man/man1/xps.1
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/xps ${PREFIX}/bin/xps

.include <bsd.port.mk>
