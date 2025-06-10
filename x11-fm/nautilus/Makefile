PORTNAME=	nautilus
PORTVERSION=	47.2
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the GNOME desktop
WWW=		https://wiki.gnome.org/Apps/Nautilus

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgexiv2.so:graphics/gexiv2 \
		libgnome-autoar-0.so:archivers/gnome-autoar \
		libportal.so:deskutils/libportal \
		libportal-gtk4.so:deskutils/libportal-gtk4 \
		libtotem.so:multimedia/totem \
		libtinysparql-3.0.so:devel/tinysparql \
		libcloudproviders.so:net/libcloudproviders
RUN_DEPENDS=	localsearch:sysutils/localsearch

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 cpe desktop-file-utils gettext gnome gstreamer localbase meson \
		pkgconfig python:build tar:xz xorg
USE_GNOME=	cairo gdkpixbuf gnomedesktop3 libadwaita
USE_LDCONFIG=	yes
USE_XORG=	x11
MESON_ARGS=	-Dpackagekit=false \
		-Dselinux=false \
		-Dtests=none
BINARY_ALIAS=	python3=${PYTHON_VERSION}
CPE_VENDOR=	gnome

GLIB_SCHEMAS=	org.gnome.nautilus.gschema.xml

CFLAGS+=	-Wno-error=strict-prototypes

OPTIONS_DEFINE=		GVFS
OPTIONS_DEFAULT=	GVFS

GVFS_USE=	GNOME=gvfs

.include <bsd.port.mk>
