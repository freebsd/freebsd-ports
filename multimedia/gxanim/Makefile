# New ports collection makefile for:	xanim
# Date created:         Sat Nov 5 11:43:03 PST 1994
# Whom:                 Rod Taylor
#
# $FreeBSD$
#

PORTNAME=	gxanim
PORTVERSION=	0.50
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.greslin.org/code/
DISTNAME=	GXAnim-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical front end to Xanim

RUN_DEPENDS=	xanim:${PORTSDIR}/multimedia/xanim

WRKSRC=	${WRKDIR}/gxanim-${PORTVERSION}

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GNOME=	gtk12

.include <bsd.port.mk>
