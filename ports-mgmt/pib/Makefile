# New ports collection makefile for:    pib
# Version required:     1.0
# Date created:         30 December 1996
# Whom:                 Mike Smith <msmith@freebsd.org>
#
# $Id$
#

DISTNAME=	pib-1.0
MASTER_SITES=	ftp://gsoft.com.au/pib/pib
CATEGORIES=	sysutils

MAINTAINER=	msmith@freebsd.org

RUN_DEPENDS=	tk-4.1

.include <bsd.port.mk>

install:
	${MKDIR} ${PREFIX}/lib/pib
	${INSTALL_SCRIPT} ${WRKSRC}/*.tcl ${PREFIX}/lib/pib
	${INSTALL_DATA} ${WRKSRC}/libTkSteal.so* ${PREFIX}/lib/pib
	ln -s ${PREFIX}/lib/pib/pib.tcl ${PREFIX}/bin/pib

