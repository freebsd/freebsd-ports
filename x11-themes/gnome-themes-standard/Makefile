# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-themes-standard
PORTVERSION=	3.22.3
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Standard themes for GNOME

LICENSE=	LGPL21

CONFLICTS=	gnome-themes-2.[0-9]*
PORTSCOUT=	limitw:1,even

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		gettext-tools gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk20 gtk30 intlhack librsvg2
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|install: install-data|install:|g' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
