# New ports collection makefile for:    pib
# Version required:     1.1
# Date created:         30 December 1996
# Whom:                 Mike Smith <msmith@freebsd.org>
#
# $Id: Makefile,v 1.7 1998/02/21 22:38:05 fenner Exp $
#

DISTNAME=	pib-1.1
CATEGORIES=	sysutils tk80
MASTER_SITES=	ftp://gsoft.com.au/pub/pib/

MAINTAINER=	msmith@freebsd.org

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

do-install:
	${MKDIR} ${PREFIX}/lib/pib
	${INSTALL_SCRIPT} ${WRKSRC}/*.tcl ${PREFIX}/lib/pib
	${INSTALL_DATA} ${WRKSRC}/libTkSteal.so* ${PREFIX}/lib/pib
	ln -fs ${PREFIX}/lib/pib/pib.tcl ${PREFIX}/bin/pib

.include <bsd.port.mk>
