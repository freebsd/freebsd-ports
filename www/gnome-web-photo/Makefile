# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/www/gnome-web-photo/Makefile,v 1.5 2007/08/07 03:27:32 mezz Exp $

PORTNAME=	gnome-web-photo
PORTVERSION=	0.10.6
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Tool to generate full-size image files and thumbnails

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libwebkitgtk-1.0.so:www/webkit-gtk2

DEPRECATED=	Uses webkit-gtk2 which has security issues
EXPIRATION_DATE=2019-03-24

USE_GNOME=	gconf2 gnomeprefix intltool
USES=		gettext gmake pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0

GCONF_SCHEMAS=	thumbnailer.schemas

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
