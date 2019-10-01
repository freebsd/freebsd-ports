# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-settings
PORTVERSION=	4.14.1
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 settings application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcolord.so:graphics/colord \
		libfontconfig.so:x11-fonts/fontconfig \
		libxklavier.so:x11/libxklavier

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce xorg
USE_GNOME=	cairo glib20 gtk30 intltool
USE_XFCE=	garcon libexo xfconf
USE_XORG=	xorgproto x11 xcursor xi xrandr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-xorg-libinput \
		--enable-pluggable-dialogs
INSTALLS_ICONS=	yes

PORTSCOUT=	limitw:1,even

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

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|Rodent|Adwaita|g' \
		${WRKSRC}/dialogs/appearance-settings/main.c
	@${REINPLACE_CMD} -e 's|IconThemeName" type="empty|IconThemeName" type="string" value="Adwaita|' \
		${WRKSRC}/xfsettingsd/xsettings.xml

.include <bsd.port.mk>
