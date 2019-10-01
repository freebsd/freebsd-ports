# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Thunar
DISTVERSION=	1.8.9
CATEGORIES=	x11-fm xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce file manager

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libtumbler-1.so:deskutils/xfce4-tumbler
RUN_DEPENDS=	pkexec:sysutils/polkit

USES=		compiler:c11 desktop-file-utils gettext-tools gmake gnome \
		libtool pathfix perl5 pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_LDCONFIG=	yes
USE_XFCE=	libexo
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gio-unix \
		--disable-gudev
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		GIR NLS NOTIFY
OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	PLUG_APR PLUG_SBR PLUG_TPA PLUG_UCA PLUG_WALL
OPTIONS_DEFAULT=	NOTIFY PLUG_APR PLUG_SBR PLUG_TPA PLUG_UCA PLUG_WALL
OPTIONS_SUB=		yes

# Override NOTIFY_DESC
GIR_DESC=	Use Gobject Introspection
NOTIFY_DESC=	Display notifications
PLUG_APR_DESC=	Advanced Properties plugin
PLUG_SBR_DESC=	Simple Builtin Renamers plugin
PLUG_TPA_DESC=	Trash Panel Applet plugin
PLUG_UCA_DESC=	User Customizable Actions plugin
PLUG_WALL_DESC=	Wallpaper plugin

GIR_USE=			gnome=introspection:build
GIR_CONFIGURE_ON=		--enable-introspection=yes
GIR_CONFIGURE_OFF=		--enable-introspection=no

NLS_CONFIGURE_ENABLE=		nls
NLS_USES=			gettext-runtime

NOTIFY_CONFIGURE_ENABLE=	notifications
NOTIFY_LIB_DEPENDS=		libnotify.so:devel/libnotify

PLUG_APR_CONFIGURE_ENABLE=	apr-plugin exif
PLUG_APR_LIB_DEPENDS=		libexif.so:graphics/libexif

PLUG_SBR_CONFIGURE_ENABLE=	sbr-plugin pcre
PLUG_SBR_LIB_DEPENDS=		libpcre.so:devel/pcre

PLUG_TPA_CONFIGURE_ENABLE=	tpa-plugin
PLUG_TPA_USE=			gnome=gvfs xfce=panel

PLUG_UCA_CONFIGURE_ENABLE=	uca-plugin
PLUG_WALL_CONFIGURE_ENABLE=	wallpaper-plugin

post-patch:
	@${REINPLACE_CMD} -e 's|mail-send|emblem-mail|' \
		${WRKSRC}/plugins/thunar-sendto-email/thunar-sendto-email.desktop.in.in

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/systemd/user/thunar.service
	(cd ${STAGEDIR}${PREFIX}/lib && ${RMDIR} -p systemd/user)

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.include <bsd.port.post.mk>
