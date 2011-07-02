# New ports collection makefile for:	gnome-web-photo
# Date created:		2005-11-30
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/gnome-web-photo/Makefile,v 1.5 2007/08/07 03:27:32 mezz Exp $
#
#

PORTNAME=	gnome-web-photo
PORTVERSION=	0.10.1
CATEGORIES=	www
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to generate full-size image files and thumbnails

LIB_DEPENDS=	webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

USE_BZIP2=	yes
USE_GNOME=	gconf2 gnomehack gnomeprefix
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-silent-rules \
		--with-gtk=2.0

GCONF_SCHEMAS=	thumbnailer.schemas

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
