PORTNAME=	epiphany
PORTVERSION=	47.7
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extremely lightweight and simple web browser for GNOME
WWW=		https://apps.gnome.org/Epiphany/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^47\.

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		iso-codes>=0:misc/iso-codes \
		itstool:textproc/itstool
LIB_DEPENDS=	libgcr-4.so:security/gcr \
		libgmp.so:math/gmp \
		libjson-glib-1.0.so:devel/json-glib \
		libsecret-1.so:security/libsecret \
		libsoup-3.0.so:devel/libsoup3 \
		libnettle.so:security/nettle \
		libportal.so:deskutils/libportal \
		libportal-gtk4.so:deskutils/libportal-gtk4 \
		libwebkitgtk-6.0.so:www/webkit2-gtk@60
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		iso-codes>=0:misc/iso-codes \
		dbus>0:devel/dbus

USES=		compiler:c++11-lib cpe desktop-file-utils gettext gnome \
		gstreamer libarchive localbase:ldflags meson pkgconfig \
		sqlite tar:xz

CPE_VENDOR=	gnome
USE_GNOME=	cairo gdkpixbuf glib20 gtk40 libadwaita libxml2
USE_LDCONFIG=	yes
MESON_ARGS=	-Db_lundef=false \
		-Dunit_tests=disabled
GLIB_SCHEMAS=	org.gnome.Epiphany.enums.xml \
		org.gnome.epiphany.gschema.xml

PLIST_SUB+=	EPHY_VERSION=${PORTVERSION:R}

.include <bsd.port.mk>
