# New ports collection makefile for:    dtv
# Date created:         10 Feb 2002
# Whom:                 dillon
#
# $FreeBSD$
#

PORTNAME=	dtv
PORTVERSION=	0.50
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://apollo.backplane.com/FreeBSDPorts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A client/server based TV capture/display program

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

USE_XORG=	xau x11 xext xxf86dga
NOT_FOR_ARCHS=	sparc64

post-patch:
	@${REINPLACE_CMD} 's|^\(LDADD +=.*\)|\1 -lxcb -lXau -lXdmcp|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
