# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	epiphany
PORTVERSION=	3.16.3
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extremely lightweight and simple web browser for GNOME 3

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		itstool:textproc/itstool \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libsoup-gnome-2.4.so:devel/libsoup-gnome \
		libgcr-3.so:security/gcr \
		libstartup-notification-1.so:x11/startup-notification \
		libnss3.so:security/nss \
		libavahi-gobject.so:net/avahi-app \
		libnotify.so:devel/libnotify \
		libsecret-1.so:security/libsecret
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		gnome-icon-theme-symbolic>=0:x11-themes/gnome-icon-theme-symbolic \
		gnome-icon-theme>=0:misc/gnome-icon-theme

PORTSCOUT=	limitw:1,even

USES=		cpe desktop-file-utils gettext gmake libtool pathfix \
		pkgconfig python:3 sqlite tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	gnomedesktop3 intlhack libwnck3 libxml2 libxslt
USE_XORG=	ice x11 sm
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=\
		--with-distributor-name="FreeBSD GNOME Project"
#		--with-ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Epiphany.enums.xml \
		org.gnome.epiphany.gschema.xml

PLIST_SUB+=	EPHY_VERSION=${PORTVERSION:R}

CONFIGURE_ARGS+=	--enable-compile-warnings=no
# for webkit2-gtk3
USES+=		compiler:c++11-lib

post-patch:
	@${REINPLACE_CMD} -e 's|execinfo.h|#|g ; s|-ldl"$$|"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
