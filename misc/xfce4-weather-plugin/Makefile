# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	xfce4-weather-plugin
PORTVERSION=	0.8.9
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

USES=		gettext gmake libtool pkgconfig xfce tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20 intltool intlhack libxml2 cairo
USE_XFCE=	panel
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	UPOWER
UPOWER_DESC=	Power management tasks

UPOWER_LIB_DEPENDS=	libupower-glib.so:sysutils/upower
UPOWER_CONFIGURE_ENABLE=	upower

.include <bsd.port.mk>
