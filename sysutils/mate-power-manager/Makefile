# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-power-manager
PORTVERSION=	1.24.0
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Power management system for the MATE Desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		gnome-keyring>=3.0.0:security/gnome-keyring
LIB_DEPENDS=	libcanberra-gtk.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libupower-glib.so:sysutils/upower \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libnotify.so:devel/libnotify \
		libunique-3.0.so:x11-toolkits/libunique3 \
		libgnome-keyring.so:security/libgnome-keyring
RUN_DEPENDS=	pkexec:sysutils/polkit \
		gnome-keyring>=3.0.0:security/gnome-keyring

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase mate \
		pathfix pkgconfig tar:xz xorg
USE_MATE=	panel
USE_XORG=	x11 xext xorgproto xrandr xrender
USE_GNOME=	cairo glib20 gtk30 intlhack
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	LIBS="-lexecinfo"
CONFIGURE_ARGS=	--with-doc-dir=${PREFIX}/share/doc \
		--disable-docbook-docs \
		--with-gtk=3.0 \
		--with-keyring

GLIB_SCHEMAS=	org.mate.power-manager.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e "s|docbook2man|docbook2man_disabled|g" \
		${WRKSRC}/configure
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/configure ${WRKSRC}/config.h.in

.include <bsd.port.mk>
