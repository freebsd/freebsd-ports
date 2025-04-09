PORTNAME=	libXaw3d
PORTVERSION=	1.6.6
CATEGORIES=	x11-toolkits

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Xaw3d is the X 3D Athena Widget Set
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:xz xorg xorg-cat:lib
USE_XORG=	x11 xau xext xmu xpm xorgproto xt

CONFIGURE_ARGS=	--without-xmlto

SUB_FILES=	pkg-message
XAWVER=		8
SUB_LIST=	XAWVER="${XAWVER}"

.include <bsd.port.mk>
