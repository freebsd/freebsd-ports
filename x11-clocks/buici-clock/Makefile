# New ports collection makefile for:	buici-clock
# Date created:		22nd Nov 2004
# Whom:				Hendrik Scholz <hscholz@raisdorf.net>
#
# $FreeBSD$
#

PORTNAME=	buici-clock
PORTVERSION=	0.4.1
CATEGORIES=	x11-clocks
MASTER_SITES=	ftp://ftp.buici.com/pub/buici-clock/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	hendrik@scholz.net
COMMENT=	Xlib implementation of an attractive, configurable clock

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BISON=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=	buici-clock.1

.include <bsd.port.mk>
