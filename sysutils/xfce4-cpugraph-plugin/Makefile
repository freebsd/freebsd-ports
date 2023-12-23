PORTNAME=	xfce4-cpugraph-plugin
PORTVERSION=	1.2.10
PORTREVISION=	1
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Graphical representation of the CPU load
WWW=		https://goodies.xfce.org/projects/panel-plugins/xfce4-cpugraph-plugin

LICENSE=	GPLv2

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c++17-lang gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce
USE_CXXSTD=	c++17
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_XFCE=	libmenu panel xfconf

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
