PORTNAME=	wpebackend-fdo
PORTVERSION=	1.8.3
CATEGORIES=	www
MASTER_SITES=	https://wpewebkit.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Freedesktop.org backend for WPE WebKit

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon \
		libwpe-1.0.so:www/libwpe \
		libwayland-client.so:graphics/wayland \
		libepoxy.so:graphics/libepoxy

USES=		compiler:c++11-lang meson pkgconfig gnome tar:xz
USE_GNOME=	glib20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
