# New ports collection makefile for:	gnome-web-photo
# Date created:		2005-11-30
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/www/gnome-web-photo/Makefile,v 1.3 2006/08/20 01:51:48 mezz Exp $
#

PORTNAME=	gnome-web-photo
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.2

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Tool to generate full-size image files and thumbnails

USE_BZIP2=	yes
USE_GECKO=	firefox seamonkey xulrunner firefox15<->firefox
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gecko=${GECKO}
USE_GMAKE=	yes
USE_XLIB=	yes
USE_GNOME=	gnomevfs2 gnomehack gnomeprefix
GCONF_SCHEMAS=	thumbnailer.schemas

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"

post-patch:
	@${REINPLACE_CMD} -e 's|libpng|libpng12|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
