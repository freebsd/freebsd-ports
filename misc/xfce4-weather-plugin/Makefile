PORTNAME=	xfce4-weather-plugin
PORTVERSION=	0.11.2
CATEGORIES=	misc xfce geography
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Weather plugin for the Xfce panel
WWW=		https://goodies.xfce.org/projects/panel-plugins/xfce4-weather-plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libjson-c.so:devel/json-c \
		libsoup-2.4.so:devel/libsoup

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool libxml2
USE_LDCONFIG=	yes
USE_XFCE=	libmenu panel xfconf

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS UPOWER
OPTIONS_SUB=	yes

UPOWER_DESC=	Power management tasks

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

UPOWER_LIB_DEPENDS=		libupower-glib.so:sysutils/upower
UPOWER_CONFIGURE_ENABLE=	upower

.include <bsd.port.mk>
