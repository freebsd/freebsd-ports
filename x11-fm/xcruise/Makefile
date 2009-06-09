# New ports collection makefile for:	xcruise
# Date created:		22 December 1999
# Whom:			minoura@netbsd.org
#
# $NetBSD: Makefile,v 1.3 1999/12/22 15:37:13 sakamoto Exp $
# $FreeBSD$
#

PORTNAME=	xcruiser
PORTVERSION=	0.30
PORTREVISION=	2
CATEGORIES=	x11-fm
MASTER_SITES=	SF

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Navigate through a three-dimensional view of a file system

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
MAN1=		xcruiser.1

post-install:
	@${MKDIR} ${PREFIX}/share/doc/xcruise
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xcruise

.include <bsd.port.mk>
