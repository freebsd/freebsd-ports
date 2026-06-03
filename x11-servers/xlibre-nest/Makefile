PORTNAME=	xlibre-nest
PORTVERSION=	${XLIBRE_VER}
PORTREVISION=	0
CATEGORIES=	x11-servers

MAINTAINER=	xlibre@FreeBSD.org
COMMENT=	Xlibre Xnest server
WWW=		https://github.com/X11Libre/xserver/

LICENSE=	MIT

CONFLICTS_INSTALL=	xorg-nestserver

USES=		xlibre-cat:server
USE_XORG+=xcb

LIB_DEPENDS+=	libxcb-util.so:x11/xcb-util \
		libxcb-icccm.so:x11/xcb-util-wm

.include 	"${.CURDIR}/../xlibre-server/Makefile.common"
