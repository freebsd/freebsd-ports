PORTNAME=	xlibre-xf86-video-ast
PORTVERSION=	1.2.0.1
CATEGORIES=	x11-drivers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre ASPEED display driver
WWW=		https://github.com/X11Libre/xf86-video-ast/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	xf86-video-ast

USES=		xlibre-cat:driver
INSTALL_TARGET=	install-strip

PLIST_FILES=	${MODULEDIR}/drivers/ast_drv.so

.include <bsd.port.mk>
