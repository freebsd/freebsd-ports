# Created by: Thorsten Greiner <thorsten.greiner@web.de>
# $FreeBSD$

PORTNAME=	xfce4-systemload-plugin
PORTVERSION=	1.2.1
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	System Load plugin for Xfce4 panel

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libupower-glib.so:sysutils/upower

SSP_UNSAFE=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gettext-tools gmake libtool pkgconfig tar:bzip2 xfce:gtk3
USE_GNOME=	gtk30 intltool cairo gdkpixbuf2
USE_XFCE=	panel

OPTIONS_DEFINE= NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime

.include <bsd.port.mk>
