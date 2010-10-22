# New ports collection makefile for:	gnome-web-photo
# Date created:		2005-11-30
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/gnome-web-photo/Makefile,v 1.5 2007/08/07 03:27:32 mezz Exp $
#
#

PORTNAME=	gnome-web-photo
PORTVERSION=	0.9
CATEGORIES=	www
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to generate full-size image files and thumbnails

USE_BZIP2=	yes
USE_GNOME=	gconf2 gnomehack gnomeprefix
USE_GECKO=	libxul
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
GCONF_SCHEMAS=	thumbnailer.schemas

CFLAGS+=	`pkg-config --cflags-only-I libxul`
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|libxul-unstable||g' ${WRKSRC}/configure

.include <bsd.port.mk>
