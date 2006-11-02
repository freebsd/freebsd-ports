# New ports collection makefile for:	xpi-unplug
# Date created:			2006/05/06
# Whom:				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	unplug
DISTVERSION=	1.4.4
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Converts embedded media to html links

XPI_ID=		unplug@compunach

post-extract:
	@${RM} ${WRKSRC}/chrome/skin/Thumbs.db
	@${MV} ${WRKSRC}/chrome/skin/lair_cache.PNG ${WRKSRC}/chrome/skin/lair_cache.png

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
