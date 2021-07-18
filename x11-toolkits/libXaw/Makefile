# Created by: Eric Anholt <anholt@FreeBSD.org>

PORTNAME=	libXaw
PORTVERSION=	1.0.14
PORTEPOCH=	2
CATEGORIES=	x11-toolkits

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Athena Widgets library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake xorg xorg-cat:lib
USE_XORG=	x11 xau xext xmu xpm xorgproto xt
CONFIGURE_ARGS=	--without-xmlto

.include <bsd.port.mk>
