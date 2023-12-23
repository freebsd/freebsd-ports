PORTNAME=	xfce4-power-manager
PORTVERSION=	4.18.3
PORTREVISION=	1
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Power manager for the Xfce Desktop
WWW=		https://goodies.xfce.org/projects/applications/xfce4-power-manager

LICENSE=	GPLv2

LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libupower-glib.so:sysutils/upower \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_XFCE=	libmenu panel xfconf
USE_XORG=	ice sm xrandr x11 xext xtst xscrnsaver

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-network-manager \
		--enable-polkit \
		--enable-xfce4panel
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.include <bsd.port.post.mk>
