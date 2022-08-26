PORTNAME=	contractor
PORTVERSION=	0.3.5
CATEGORIES=	sysutils

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Desktop-wide extension service

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libgee-0.8.so:devel/libgee

USES=		gettext-runtime gnome meson pkgconfig tar:xz vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	glib20

.include <bsd.port.mk>
