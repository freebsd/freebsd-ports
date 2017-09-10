# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	epiphany
PORTVERSION=	3.24.2
PORTREVISION=	1
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
		libgcr-3.so:security/gcr \
		libstartup-notification-1.so:x11/startup-notification \
		libnss3.so:security/nss \
		libjson-glib-1.0.so:devel/json-glib \
		libicuuc.so:devel/icu \
		libavahi-gobject.so:net/avahi-app \
		libnotify.so:devel/libnotify \
		libsecret-1.so:security/libsecret \
		libp11-kit.so:security/p11-kit
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		gnome-icon-theme-symbolic>=0:x11-themes/gnome-icon-theme-symbolic \
		gnome-icon-theme>=0:misc/gnome-icon-theme

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib cpe desktop-file-utils gettext gmake gnome \
		libtool localbase pathfix pkgconfig python:3.3+ sqlite tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	cairo gnomedesktop3 intlhack libwnck3 libxml2 libxslt
USE_XORG=	x11
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=\
		--with-distributor-name="FreeBSD GNOME Project"
#		--with-ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Epiphany.enums.xml \
		org.gnome.epiphany.gschema.xml

PLIST_SUB+=	EPHY_VERSION=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e 's|execinfo.h|#|g ; s|-ldl"$$|"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
