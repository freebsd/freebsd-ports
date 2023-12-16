PORTNAME=	elementary
PORTVERSION=	0.18
DISTVERSIONPREFIX=v
CATEGORIES=	x11-themes xfce
PKGNAMEPREFIX=	xfce-icons-

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Elementary icons, extended and maintained for Xfce
WWW=		https://github.com/shimmerproject/elementary-xfce

LICENSE=	GPLv2

BUILD_DEPENDS=	optipng:graphics/optipng

USES=		compiler:c11 gnome pkgconfig
USE_GNOME=	gdkpixbuf2:build gtk30:build

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}"

USE_GITHUB=	yes
GH_ACCOUNT=	shimmerproject
GH_PROJECT=	elementary-xfce

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O0|${CFLAGS}|' \
		${WRKSRC}/svgtopng/Makefile

.include <bsd.port.mk>
