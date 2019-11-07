# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	epiphany
PORTVERSION=	3.28.5
PORTREVISION=	5
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extremely lightweight and simple web browser for GNOME 3

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		itstool:textproc/itstool \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libsoup-2.4.so:devel/libsoup \
		libsoup-gnome-2.4.so:devel/libsoup-gnome \
		libsoup-2.4.so:devel/libsoup \
		libgcr-3.so:security/gcr \
		libstartup-notification-1.so:x11/startup-notification \
		libnss3.so:security/nss \
		libjson-glib-1.0.so:devel/json-glib \
		libicuuc.so:devel/icu \
		libavahi-gobject.so:net/avahi-app \
		libnotify.so:devel/libnotify \
		libgmp.so:math/gmp \
		libnettle.so:security/nettle \
		libsecret-1.so:security/libsecret \
		libp11-kit.so:security/p11-kit
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		gnome-icon-theme-symbolic>=0:x11-themes/gnome-icon-theme-symbolic \
		gnome-icon-theme>=0:misc/gnome-icon-theme

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib cpe desktop-file-utils gettext gnome \
		localbase:ldflags meson pkgconfig python:3.4+ shebangfix \
		sqlite tar:xz xorg
CPE_VENDOR=	gnome
USE_GNOME=	cairo gnomedesktop3 intlhack libwnck3 libxml2 libxslt
USE_XORG=	x11
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddistributor_name="GNOME Web by the FreeBSD GNOME Project" \
		-Db_lundef=false \
		-Dunit_tests=false
GLIB_SCHEMAS=	org.gnome.Epiphany.enums.xml \
		org.gnome.epiphany.gschema.xml
SHEBANG_FILES=	post_install.py

PLIST_SUB+=	EPHY_VERSION=${PORTVERSION:R}

.include <bsd.port.mk>
