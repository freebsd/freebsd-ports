# New ports collection makefile for:    pib
# Version required:     1.1
# Date created:         30 December 1996
# Whom:                 Mike Smith <msmith@freebsd.org>
#
# $Id: Makefile,v 1.9 1998/09/03 16:02:35 msmith Exp $
#

DISTNAME=	pib-1.1
CATEGORIES=	sysutils tk80
MASTER_SITES=	ftp://gsoft.com.au/pub/pib/

MAINTAINER=	msmith@freebsd.org

BUILD_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80
RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

do-install:
	${MKDIR} ${PREFIX}/lib/pib
	${INSTALL_SCRIPT} ${WRKSRC}/*.tcl ${PREFIX}/lib/pib
	${INSTALL_DATA} ${WRKSRC}/libTkSteal.so* ${PREFIX}/lib/pib
	ln -fs ${PREFIX}/lib/pib/pib.tcl ${PREFIX}/bin/pib

.include <bsd.port.mk>
