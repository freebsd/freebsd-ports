# Created by: ade, archie

PORTNAME=	nautilus
PORTVERSION=	41.1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the GNOME desktop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgexiv2.so:graphics/gexiv2 \
		libgnome-autoar-0.so:archivers/gnome-autoar \
		libhandy-1.so:x11-toolkits/libhandy \
		libportal.so:deskutils/libportal \
		libtotem.so:multimedia/totem \
		libtracker-sparql-3.0.so:sysutils/tracker3

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 cpe desktop-file-utils gettext gnome localbase meson \
		pkgconfig python:3.6+,build tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3
USE_GSTREAMER1=	yes
USE_LDCONFIG=	yes
USE_XORG=	x11
MESON_ARGS=	-Dpackagekit=false \
		-Dselinux=false
BINARY_ALIAS=	python3=${PYTHON_VERSION}
CPE_VENDOR=	gnome

GLIB_SCHEMAS=	org.gnome.nautilus.gschema.xml

OPTIONS_DEFINE=		GVFS
OPTIONS_DEFAULT=	GVFS

GVFS_USE=	GNOME=gvfs

.include <bsd.port.mk>
