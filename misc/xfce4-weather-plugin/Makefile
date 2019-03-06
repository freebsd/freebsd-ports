# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	xfce4-weather-plugin
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	misc xfce geography
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Weather plugin for the Xfce panel

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext-tools gmake gnome libtool pkgconfig tar:bzip2 xfce:gtk3
USE_GNOME=	cairo glib20 gtk30 intltool libxml2
USE_XFCE=	panel
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS UPOWER
OPTIONS_SUB=	yes

UPOWER_DESC=	Power management tasks

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

UPOWER_LIB_DEPENDS=	libupower-glib.so:sysutils/upower
UPOWER_CONFIGURE_ENABLE=upower

.include <bsd.port.mk>
