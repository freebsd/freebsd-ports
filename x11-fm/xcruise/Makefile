# New ports collection makefile for:	xcruise
# Date created:		22 December 1999
# Whom:			minoura@netbsd.org
#
# $NetBSD: Makefile,v 1.3 1999/12/22 15:37:13 sakamoto Exp $
# $FreeBSD$
#

PORTNAME=	xcruise
PORTVERSION=	0.24
CATEGORIES=	x11-fm
MASTER_SITES=	http://tanaka-www.cs.titech.ac.jp/%7Eeuske/prog/

MAINTAINER=	sanpei@FreeBSD.org

USE_IMAKE=	yes

post-install:
	@${MKDIR} ${PREFIX}/share/doc/xcruise
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xcruise

.include <bsd.port.mk>
