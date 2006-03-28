# New ports collection makefile for:	gnome-web-photo
# Date created:		2005-11-30
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/www/gnome-web-photo/Makefile,v 1.1 2005/12/01 06:25:42 ahze Exp $
#

PORTNAME=	gnome-web-photo
PORTVERSION=	0.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.2

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Tool to generate full-size image files and thumbnails

USE_BZIP2=	yes
USE_GECKO=	firefox seamonkey xulrunner
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gecko=${GECKO}
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomevfs2 gnomehack
GCONF_SCHEMAS=	thumbnailer.schemas

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"

post-patch:
	@${REINPLACE_CMD} -e 's|libpng|libpng12|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
