# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	battfink
PORTVERSION=	0.6.2
PORTREVISION=	16
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Energy saving preferences app for GNOME

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

INSTALLS_OMF=	yes
USE_GNOME=	gnomeprefix libgnomeui
USES=		gettext gmake localbase pathfix pkgconfig tar:bzip2
USE_XORG=	x11 xext
GNU_CONFIGURE=	yes
LIBS+=		-lX11 -lXext
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	battfink.schemas

.include <bsd.port.mk>
