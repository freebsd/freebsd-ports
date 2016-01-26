# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-power-manager
PORTVERSION=	1.12.1
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Power management system for the MATE Desktop

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool \
		gnome-keyring>=3.0.0:${PORTSDIR}/security/gnome-keyring
LIB_DEPENDS=	libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique \
		libupower-glib.so:${PORTSDIR}/sysutils/upower \
		libnotify.so:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	pkexec:${PORTSDIR}/sysutils/polkit \
		gnome-keyring>=3.0.0:${PORTSDIR}/security/gnome-keyring

PORTSCOUT=	limitw:1,even

USES=		execinfo gettext gmake libtool pathfix pkgconfig tar:xz
USE_MATE=	panel
USE_XORG=	x11 xext xproto xrandr xrender
USE_GNOME=	cairo glib20 gtk20 intlhack
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	LIBS="-lexecinfo"
CONFIGURE_ARGS=	--with-doc-dir=${PREFIX}/share/doc \
		--disable-docbook-docs \
		--with-gtk=2.0 \
		--with-keyring
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.power-manager.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e "s|docbook2man|docbook2man_disabled|g" \
		${WRKSRC}/configure
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/configure ${WRKSRC}/config.h.in

.include <bsd.port.mk>
