# Created by: Matthias Petermann <matthias@petermann-it.de>

PORTNAME=	elementary
PORTVERSION=	0.17
DISTVERSIONPREFIX=v
CATEGORIES=	x11-themes xfce
PKGNAMEPREFIX=	xfce-icons-

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Elementary icons, extended and maintained for Xfce

LICENSE=	GPLv2

BUILD_DEPENDS=	optipng:graphics/optipng

USES=		compiler:c11 gnome pkgconfig
USE_GNOME=	gdkpixbuf2:build gtk30:build

HAS_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	shimmerproject
GH_PROJECT=	elementary-xfce

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e 's|\/$$(PREFIX)|$$(PREFIX)|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
