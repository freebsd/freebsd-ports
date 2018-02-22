# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Thunar
DISTVERSION=	1.6.14
PORTREVISION=	1
CATEGORIES=	x11-fm xfce
MASTER_SITES=	XFCE/src/xfce/${PORTNAME:tl}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce file manager

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libtumbler-1.so:deskutils/xfce4-tumbler \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	pkexec:sysutils/polkit

PORTSCOUT=	limit:^1\.6\.

USES=		desktop-file-utils gmake pathfix perl5 libtool pkgconfig \
		gettext-tools xfce tar:bzip2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	glib20 gtk20 intltool cairo gdkpixbuf2
USE_LDCONFIG=	yes
USE_XFCE=	libexo
USE_XORG=	ice sm x11
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS NOTIFY
OPTIONS_GROUP=	PLUGINS
OPTIONS_GROUP_PLUGINS=	PLUG_APR PLUG_SBR PLUG_TPA PLUG_UCA PLUG_WALL
OPTIONS_DEFAULT=	NOTIFY PLUG_APR PLUG_SBR PLUG_UCA PLUG_TPA PLUG_WALL

# Override NOTIFY_DESC
NOTIFY_DESC=	Display notifications
PLUG_APR_DESC=	Advanced Properties plugin
PLUG_SBR_DESC=	Simple Builtin Renamers plugin
PLUG_TPA_DESC=	Trash Panel Applet plugin
PLUG_UCA_DESC=	User Customizable Actions plugin
PLUG_WALL_DESC=	Wallpaper plugin

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=	notifications
PLUG_APR_LIB_DEPENDS=	libexif.so:graphics/libexif
PLUG_APR_CONFIGURE_ENABLE=	apr-plugin exif
PLUG_SBR_LIB_DEPENDS=	libpcre.so:devel/pcre
PLUG_SBR_CONFIGURE_ENABLE=	sbr-plugin pcre
PLUG_TPA_USE=	gnome=gvfs xfce=panel
PLUG_TPA_CONFIGURE_ENABLE=	tpa-plugin
PLUG_UCA_CONFIGURE_ENABLE=	uca-plugin
PLUG_WALL_CONFIGURE_ENABLE=	wallpaper-plugin
OPTIONS_SUB=	yes

CONFIGURE_ARGS+=--enable-gio-unix \
		--disable-gudev \
		--enable-dbus

post-patch:
	@${REINPLACE_CMD} -e 's|internet-mail|emblem-mail|' \
		${WRKSRC}/plugins/thunar-sendto-email/thunar-sendto-email.desktop.in.in

.include <bsd.port.mk>
