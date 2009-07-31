# New ports collection makefile for:	gnome-web-photo
# Date created:		2005-11-30
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/gnome-web-photo/Makefile,v 1.5 2007/08/07 03:27:32 mezz Exp $
#
#

PORTNAME=	gnome-web-photo
PORTVERSION=	0.2
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	GNOME

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Tool to generate full-size image files and thumbnails

USE_BZIP2=	yes
USE_GECKO=	firefox seamonkey xulrunner
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gecko=${GECKO}
USE_GMAKE=	yes
USE_GNOME=	gnomevfs2 gnomehack gnomeprefix
GCONF_SCHEMAS=	thumbnailer.schemas

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"

post-patch:
	@${REINPLACE_CMD} -e 's|libpng|libpng12|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
