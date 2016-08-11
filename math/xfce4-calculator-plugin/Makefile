# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	xfce4-calculator-plugin
PORTVERSION=	0.6.0
CATEGORIES=	math xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Simple calculator for the Xfce panel

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
	libfreetype.so:print/freetype2

USES=	gmake gettext-tools libtool pkgconfig tar:bz2 xfce
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 cairo intltool intlhack
USE_XFCE=	panel
USE_XORG=	x11
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
