# New ports collection makefile for:    pib
# Date created:         30 December 1996
# Whom:                 Mike Smith <msmith@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pib
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	ports-mgmt tk
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	msmith

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI Ports Collection management tool

USE_TK=		84
USE_TK_BUILD=	84

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/lib/pib
	${INSTALL_SCRIPT} ${WRKSRC}/*.tcl ${PREFIX}/lib/pib
	${INSTALL_DATA} ${WRKSRC}/libTkSteal.so.2* ${PREFIX}/lib/pib
	${LN} -fs ${PREFIX}/lib/pib/pib.tcl ${PREFIX}/bin/pib

.include <bsd.port.post.mk>
