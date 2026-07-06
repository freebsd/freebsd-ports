PORTNAME=	xf86-video-ast
DISTVERSION=	1.2.1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ASPEED display driver
WWW=		https://gitlab.freedesktop.org/xorg/driver/xf86-video-ast

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	Calls into x86-specific xorg/compiler.h functions

USES=		tar:xz xorg-cat:driver

PLIST_FILES=	lib/xorg/modules/drivers/ast_drv.so

.include <bsd.port.mk>
