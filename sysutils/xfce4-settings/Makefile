# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-settings
PORTVERSION=	4.12.4
PORTREVISION=	3
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/src/xfce/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 settings application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libxklavier.so:x11/libxklavier

USES=		gettext-tools gmake gnome libtool pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo glib20 gtk20 intlhack intltool
USE_XFCE=	garcon libexo
USE_XORG=	xorgproto x11 xcursor xi xrandr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-debug=yes \
		--disable-xorg-libinput
INSTALLS_ICONS=	yes

PORTSCOUT=	limit:^4\.12\.

OPTIONS_DEFINE=		NOTIFY NLS UPOWER
OPTIONS_DEFAULT=	NOTIFY
OPTIONS_SUB=		yes

UPOWER_DESC=		Power management tasks

NLS_CONFIGURE_ENABLE=		nls
NLS_USES=			gettext-runtime

NOTIFY_CONFIGURE_ENABLE=	libnotify
NOTIFY_LIB_DEPENDS=		libnotify.so:devel/libnotify

UPOWER_CONFIGURE_ENABLE=	upower-glib
UPOWER_LIB_DEPENDS=		libupower-glib.so:sysutils/upower

post-patch:
	@${REINPLACE_CMD} -e 's|Rodent|Adwaita|g' \
		${WRKSRC}/dialogs/appearance-settings/main.c
	@${REINPLACE_CMD} -e 's|IconThemeName" type="empty|IconThemeName" type="string" value="Adwaita|; \
		s|"ThemeName" type="empty|"ThemeName" type="string" value="Xfce|' \
		${WRKSRC}/xfsettingsd/xsettings.xml

.include <bsd.port.mk>
