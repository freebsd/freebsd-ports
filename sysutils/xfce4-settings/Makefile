# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-settings
PORTVERSION=	4.12.3
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
		libxklavier.so:x11/libxklavier

PORTSCOUT=	limit:^4\.12\.

USES=		gettext-tools gmake libtool pkgconfig tar:bzip2 xfce
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	glib20 gtk20 cairo intltool intlhack
USE_XFCE=	garcon libexo
USE_XORG=	inputproto x11 xcursor xi xrandr

CONFIGURE_ARGS=	--enable-debug=yes \
		--disable-xorg-libinput

OPTIONS_DEFINE=		NOTIFY NLS UPOWER
OPTIONS_DEFAULT=	NOTIFY

UPOWER_DESC=		Power management tasks

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=	libnotify
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime
UPOWER_LIB_DEPENDS=	libupower-glib.so:sysutils/upower
UPOWER_CONFIGURE_ENABLE=	upower-glib
OPTIONS_SUB=		yes

post-patch:
	@${REINPLACE_CMD} -e 's|Rodent|Adwaita|g' \
		${WRKSRC}/dialogs/appearance-settings/main.c
	@${REINPLACE_CMD} -e 's|IconThemeName" type="empty|IconThemeName" type="string" value="Adwaita|; \
		s|"ThemeName" type="empty|"ThemeName" type="string" value="Xfce|' \
		${WRKSRC}/xfsettingsd/xsettings.xml

.include <bsd.port.mk>
