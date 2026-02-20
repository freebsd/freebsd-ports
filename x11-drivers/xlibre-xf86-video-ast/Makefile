PORTNAME=	xlibre-xf86-video-ast
PORTVERSION=	25.0.0
PORTREVISION=	1
CATEGORIES=	x11-drivers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre ASPEED display driver
WWW=		https://github.com/X11Libre/xf86-video-ast/

ONLY_FOR_ARCHS=	amd64 i386

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xlibre-cat:driver
INSTALL_TARGET=	install-strip

PLIST_FILES=	${MODULEDIR}/drivers/ast_drv.so

.include <bsd.port.mk>
