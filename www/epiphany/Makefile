# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	epiphany
PORTVERSION=	42.0
CATEGORIES=	www gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extremely lightweight and simple web browser for GNOME 3

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		iso-codes>=0:misc/iso-codes \
		itstool:textproc/itstool
LIB_DEPENDS=	libdazzle-1.0.so:x11-toolkits/libdazzle \
		libgcr-base-3.so:security/gcr \
		libgmp.so:math/gmp \
		libhandy-1.so:x11-toolkits/libhandy \
		libicuuc.so:devel/icu \
		libjson-glib-1.0.so:devel/json-glib \
		libnettle.so:security/nettle \
		libnotify.so:devel/libnotify \
		libnss3.so:security/nss \
		libp11-kit.so:security/p11-kit \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libstartup-notification-1.so:x11/startup-notification \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3
RUN_DEPENDS=	gnome-icon-theme-symbolic>=0:x11-themes/gnome-icon-theme-symbolic \
		gnome-icon-theme>=0:misc/gnome-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		iso-codes>=0:misc/iso-codes

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib cpe desktop-file-utils gettext gnome \
		libarchive localbase:ldflags meson pkgconfig python:3.4+ \
		shebangfix sqlite tar:xz xorg

CPE_VENDOR=	gnome
USE_GNOME=	cairo gnomedesktop3 intlhack libwnck3 libxml2 libxslt
USE_XORG=	x11
USE_LDCONFIG=	yes
MESON_ARGS=	-Db_lundef=false \
		-Dunit_tests=disabled
GLIB_SCHEMAS=	org.gnome.Epiphany.enums.xml \
		org.gnome.epiphany.gschema.xml
SHEBANG_FILES=	post_install.py

PLIST_SUB+=	EPHY_VERSION=${PORTVERSION:R}

.include <bsd.port.mk>
