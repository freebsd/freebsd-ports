PORTNAME=	nautilus
PORTVERSION=	42.2
PORTREVISION=	3
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the GNOME desktop
WWW=		https://wiki.gnome.org/Apps/Nautilus

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgexiv2.so:graphics/gexiv2 \
		libgnome-autoar-0.so:archivers/gnome-autoar \
		libhandy-1.so:x11-toolkits/libhandy \
		libportal.so:deskutils/libportal \
		libportal-gtk3.so:deskutils/libportal-gtk3 \
		libtotem.so:multimedia/totem \
		libtracker-sparql-3.0.so:sysutils/tracker3

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 cpe desktop-file-utils gettext gnome gstreamer localbase meson \
		pkgconfig python:build tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3
USE_LDCONFIG=	yes
USE_XORG=	x11
MESON_ARGS=	-Dpackagekit=false \
		-Dselinux=false
BINARY_ALIAS=	python3=${PYTHON_VERSION}
CPE_VENDOR=	gnome

GLIB_SCHEMAS=	org.gnome.nautilus.gschema.xml

CFLAGS+=	-Wno-error=strict-prototypes

OPTIONS_DEFINE=		GVFS
OPTIONS_DEFAULT=	GVFS

GVFS_USE=	GNOME=gvfs

.include <bsd.port.mk>
