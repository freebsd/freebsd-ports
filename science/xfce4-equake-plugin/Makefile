# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	xfce4-equake-plugin
PORTVERSION=	1.3.8.1
PORTREVISION=	1
CATEGORIES=	science xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Earthquake monitor plugin for the Xfce panel

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libcurl.so:ftp/curl

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce:gtk2 xorg
USE_GNOME=	cairo glib20 gtk20 intltool
USE_XFCE=	panel
USE_XORG=	x11

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
