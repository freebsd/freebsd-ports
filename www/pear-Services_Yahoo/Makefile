# Ports collection makefile for:  pear-Services_Yahoo
# Date created:			  10 Dez 2008
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Services_Yahoo
PORTVERSION=	0.2.0
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Provides access to the Yahoo! Web Services

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

CATEGORY=	Services
FILES=		Yahoo/ContentAnalysis/AbstractContentAnalysis.php Yahoo/ContentAnalysis/Response.php \
		Yahoo/ContentAnalysis/spellingSuggestion.php Yahoo/ContentAnalysis/termExtraction.php \
		Yahoo/Maps/Request.php Yahoo/Maps/XMLDocument.php Yahoo/Search/AbstractSearch.php \
		Yahoo/Search/Response.php Yahoo/Search/image.php Yahoo/Search/local.php Yahoo/Search/news.php \
		Yahoo/Search/video.php Yahoo/Search/web.php Yahoo/Tests/All.php Yahoo/Tests/Exception.php \
		Yahoo/Tests/Search.php Yahoo/Exception.php Yahoo/ContentAnalysis.php Yahoo/Search.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
