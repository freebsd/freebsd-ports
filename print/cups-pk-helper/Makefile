PORTNAME=	cups-pk-helper
PORTVERSION=	0.2.7
CATEGORIES=	print
MASTER_SITES=	https://www.freedesktop.org/software/${PORTNAME}/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Helper that makes system-config-printer use polkit
WWW=		https://www.freedesktop.org/software/cups-pk-helper

LICENSE=	GPLv2+

LIB_DEPENDS=	libcups.so:print/cups \
		libpolkit-gobject-1.so:sysutils/polkit

USE_GNOME=	glib20 intltool
USES=		cpe gettext gnome localbase meson pkgconfig tar:xz
CPE_VENDOR=	cups-pk-helper_project

.include <bsd.port.mk>
