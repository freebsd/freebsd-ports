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

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

ONLY_FOR_ARCHS=	amd64 i386

USES=		alias gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 gtk30 glib20 intltool
USE_XFCE=	libmenu panel
USE_LDCONFIG=	yes

SSP_UNSAFE=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
