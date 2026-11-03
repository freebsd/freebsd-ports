PORTNAME=	xf86-video-ast
DISTVERSION=	1.2.1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ASPEED display driver
WWW=		https://gitlab.freedesktop.org/xorg/driver/xf86-video-ast

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	needs the inb/outb helpers of xorg/compiler.h, which exist only on x86 and powerpc

USES=		xorg-cat:driver

PLIST_FILES=	lib/xorg/modules/drivers/ast_drv.so

.include <bsd.port.mk>
