# $FreeBSD$

PORTNAME=	wpebackend-fdo
PORTVERSION=	1.4.1
CATEGORIES=	www
MASTER_SITES=	https://wpewebkit.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Freedesktop.org backend for WPE WebKit

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon \
		libwpe-1.0.so:www/libwpe \
		libwayland-client.so:graphics/wayland

USES=		cmake compiler:c++11-lang pkgconfig localbase:ldflags gl gnome \
		tar:xz

USE_GL=		egl
USE_GNOME=	glib20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
