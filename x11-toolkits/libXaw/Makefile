# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libXaw
PORTVERSION=	1.0.13
PORTEPOCH=	2
CATEGORIES=	x11-toolkits

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Athena Widgets library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
XORG_CAT=	lib
USE_XORG=	printproto:both x11 xau xext xextproto xmu xp xpm xproto:both xt
CONFIGURE_ARGS=	--without-xmlto

.include <bsd.port.mk>
