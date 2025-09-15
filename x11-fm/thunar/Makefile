PORTNAME=	thunar
DISTVERSION=	4.20.5
CATEGORIES=	x11-fm xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce file manager
WWW=		https://gitlab.xfce.org/xfce/thunar

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	pkexec:sysutils/polkit \
		xfce4-tumbler>0:deskutils/xfce4-tumbler

USES=		compiler:c11 cpe desktop-file-utils gettext-tools gmake gnome \
		libtool pathfix perl5 pkgconfig tar:bzip2 xfce xorg
CPE_VENDOR=	xfce
USE_GNOME=	cairo gdkpixbuf glib20 gtk30
USE_LDCONFIG=	yes
USE_XFCE=	libexo panel xfconf
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gudev \
		--enable-gio-unix
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		GIR NLS NOTIFY
OPTIONS_DEFAULT=	NOTIFY PLUG_APR PLUG_SBR PLUG_TPA PLUG_UCA PLUG_WALL
OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	PLUG_APR PLUG_SBR PLUG_TPA PLUG_UCA PLUG_WALL
OPTIONS_SUB=		yes

# Override NOTIFY_DESC
GIR_DESC=	Use Gobject Introspection
NOTIFY_DESC=	Display notifications
PLUG_APR_DESC=	Advanced Properties plugin
PLUG_SBR_DESC=	Simple Builtin Renamers plugin
PLUG_TPA_DESC=	Trash Panel Applet plugin
PLUG_UCA_DESC=	User Customizable Actions plugin
PLUG_WALL_DESC=	Wallpaper plugin

GIR_USE=		GNOME=introspection:build
GIR_CONFIGURE_ON=	--enable-introspection=yes
GIR_CONFIGURE_OFF=	--enable-introspection=no

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

NOTIFY_LIB_DEPENDS=		libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=	notifications

PLUG_APR_LIB_DEPENDS=		libexif.so:graphics/libexif
PLUG_APR_CONFIGURE_ENABLE=	apr-plugin exif

PLUG_SBR_LIB_DEPENDS=		libpcre2-8.so:devel/pcre2
PLUG_SBR_CONFIGURE_ENABLE=	sbr-plugin

PLUG_TPA_USE=			GNOME=gvfs \
				XFCE=panel
PLUG_TPA_CONFIGURE_ENABLE=	tpa-plugin

PLUG_UCA_CONFIGURE_ENABLE=	uca-plugin

PLUG_WALL_CONFIGURE_ENABLE=	wallpaper-plugin

post-patch:
	@${REINPLACE_CMD} -e 's|mail-send|emblem-mail|' \
		${WRKSRC}/plugins/thunar-sendto-email/thunar-sendto-email.desktop.in.in
.for f in org.xfce.FileManager org.xfce.Thunar.FileManager1 org.xfce.Thunar
	@${REINPLACE_CMD} -i "" -e 's|SystemdService|#SystemdService|' \
		${WRKSRC}/${f}.service.in
.endfor

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.include <bsd.port.post.mk>
