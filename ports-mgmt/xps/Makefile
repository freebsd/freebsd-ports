# New ports collection makefile for:   xps
# Date created:        4 December 2008
# Whom:                antonakis@gmail.com
#
# $FreeBSD$

PORTNAME=	xps
PORTVERSION=	0.3
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.crucible.gr:5555/

MAINTAINER=	antonakis@gmail.com
COMMENT=	A tool that searches the ports tree by various criteria.

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/xps

MAN1=	xps.1

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/xps.1 ${PREFIX}/man/man1/xps.1
	${INSTALL_SCRIPT} ${WRKDIR}/xps ${PREFIX}/bin/xps

.include <bsd.port.mk>
