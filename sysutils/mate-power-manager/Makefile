PORTNAME=	mate-power-manager
DISTVERSION=	1.28.1
PORTREVISION=	2
CATEGORIES=	sysutils mate
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Power management system for the MATE Desktop
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libnotify.so:devel/libnotify \
		libsecret-1.so:security/libsecret \
		libunique-3.0.so:x11-toolkits/libunique3 \
		libupower-glib.so:sysutils/upower
RUN_DEPENDS=	pkexec:sysutils/polkit

USES=		gettext gmake gnome libtool localbase mate pathfix pkgconfig \
		tar:xz xorg
USE_GITHUB=	nodefault
GH_ACCOUNT=	mate-desktop
USE_MATE=	panel
USE_XORG=	x11 xext xorgproto xrandr xrender
USE_GNOME=	cairo glib20 gtk30 intlhack
PORTSCOUT=	site:https://github.com/mate-desktop/mate-power-manager/releases/ limitw:1,even
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	LIBS="-lexecinfo"
CONFIGURE_ARGS=	--disable-docbook-docs \
		--with-doc-dir=${PREFIX}/share/doc \
		--with-gtk=3.0

GLIB_SCHEMAS=	org.mate.power-manager.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e "s|docbook2man|docbook2man_disabled|g" \
		${WRKSRC}/configure
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/configure ${WRKSRC}/config.h.in

.include <bsd.port.mk>
