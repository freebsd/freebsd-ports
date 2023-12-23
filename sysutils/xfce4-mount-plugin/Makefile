PORTNAME=	xfce4-mount-plugin
PORTVERSION=	1.1.6
PORTREVISION=	2
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Mount and umount utility for the Xfce4 panel
WWW=		https://goodies.xfce.org/projects/panel-plugins/xfce4-mount-plugin

LICENSE=	GPLv2

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_LDCONFIG=	yes
USE_XFCE=	libmenu panel

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
