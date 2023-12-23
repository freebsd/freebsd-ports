PORTNAME=	xfce4-calculator-plugin
PORTVERSION=	0.7.2
PORTREVISION=	2
CATEGORIES=	math xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Simple calculator for the Xfce panel
WWW=		https://goodies.xfce.org/projects/panel-plugins/xfce4-calculator-plugin

LICENSE=	GPLv2

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bz2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_XFCE=	libmenu panel
USE_XORG=	x11

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
