PORTNAME=	xfce4-systemload-plugin
PORTVERSION=	1.4.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	System Load plugin for Xfce4 panel
WWW=		https://docs.xfce.org/panel-plugins/xfce4-systemload-plugin/start

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz xfce
USE_GNOME=	gtk30
USE_XFCE=	libmenu panel xfconf
SSP_UNSAFE=	yes

OPTIONS_DEFINE=		LIBGTOP NLS UPOWER
OPTIONS_DEFAULT=	UPOWER
OPTIONS_SUB=		yes

LIBGTOP_DESC=	Use libgtop for network utilization monitoring
UPOWER_DESC=	Use upower for adapting update interval to power state

LIBGTOP_LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop
LIBGTOP_MESON_ENABLED=	libgtop

NLS_USES=	gettext-runtime

UPOWER_LIB_DEPENDS=	libupower-glib.so:sysutils/upower
UPOWER_MESON_ENABLED=	upower-glib

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
