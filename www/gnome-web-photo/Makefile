# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/www/gnome-web-photo/Makefile,v 1.5 2007/08/07 03:27:32 mezz Exp $

PORTNAME=	gnome-web-photo
PORTVERSION=	0.10.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Tool to generate full-size image files and thumbnails

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	webkitgtk-1.0.0:${PORTSDIR}/www/webkit-gtk2

USE_XZ=		yes
USE_GNOME=	gconf2 gnomehack gnomeprefix
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--with-gtk=2.0

GCONF_SCHEMAS=	thumbnailer.schemas

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
