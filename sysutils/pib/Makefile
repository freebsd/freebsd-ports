# New ports collection makefile for:    pib
# Version required:     1.0
# Date created:         30 December 1996
# Whom:                 Mike Smith <msmith@freebsd.org>
#
# $Id: Makefile,v 1.2 1996/12/30 09:26:23 msmith Exp $
#

DISTNAME=	pib-1.0
MASTER_SITES=	ftp://gsoft.com.au/pub/pib/
CATEGORIES=	sysutils

MAINTAINER=	msmith@freebsd.org

RUN_DEPENDS=	wish4.1:${PORTSDIR}/x11/tk41

do-install:
	${MKDIR} ${PREFIX}/lib/pib
	${INSTALL_SCRIPT} ${WRKSRC}/*.tcl ${PREFIX}/lib/pib
	${INSTALL_DATA} ${WRKSRC}/libTkSteal.so* ${PREFIX}/lib/pib
	ln -fs ${PREFIX}/lib/pib/pib.tcl ${PREFIX}/bin/pib

.include <bsd.port.mk>
