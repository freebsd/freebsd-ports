# New ports collection makefile for:    pib
# Version required:     1.1
# Date created:         30 December 1996
# Whom:                 Mike Smith <msmith@freebsd.org>
#
# $Id: Makefile,v 1.4 1997/04/20 13:19:45 wosch Exp $
#

DISTNAME=	pib-1.1
MASTER_SITES=	ftp://gsoft.com.au/pub/pib/
CATEGORIES=	sysutils

MAINTAINER=	msmith@freebsd.org

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80

do-install:
	${MKDIR} ${PREFIX}/lib/pib
	${INSTALL_SCRIPT} ${WRKSRC}/*.tcl ${PREFIX}/lib/pib
	${INSTALL_DATA} ${WRKSRC}/libTkSteal.so* ${PREFIX}/lib/pib
	ln -fs ${PREFIX}/lib/pib/pib.tcl ${PREFIX}/bin/pib

.include <bsd.port.mk>
