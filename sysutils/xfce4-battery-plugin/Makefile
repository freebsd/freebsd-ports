PORTNAME=	xfce4-battery-plugin
PORTVERSION=	1.1.5
PORTREVISION=	2
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Battery monitor panel plugin for Xfce4
WWW=		https://goodies.xfce.org/projects/panel-plugins/xfce4-battery-plugin

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		alias gettext-tools gmake gnome libtool pkgconfig tar:bzip2 \
		xfce
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_LDCONFIG=	yes
USE_XFCE=	libmenu panel

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
SSP_UNSAFE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
