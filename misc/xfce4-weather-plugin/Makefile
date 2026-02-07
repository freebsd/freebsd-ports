PORTNAME=	xfce4-weather-plugin
PORTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	misc xfce geography
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Weather plugin for the Xfce panel
WWW=		https://goodies.xfce.org/projects/panel-plugins/xfce4-weather-plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libsoup-2.4.so:devel/libsoup

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz xfce
USE_GNOME=	glib20 gtk30 libxml2
USE_LDCONFIG=	yes
USE_XFCE=	libmenu panel xfconf

OPTIONS_DEFINE=	NLS UPOWER
OPTIONS_SUB=	yes

UPOWER_DESC=	Power management tasks

NLS_USES=	gettext-runtime

UPOWER_LIB_DEPENDS=	libupower-glib.so:sysutils/upower
UPOWER_MESON_ENABLED=	upower-glib

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
