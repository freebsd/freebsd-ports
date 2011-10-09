# New ports collection makefile for:	newsfeed
# Date created:		23 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	newsfeed
PORTVERSION=	2.14
CATEGORIES=	www
MASTER_SITES=	http://home.arcor.de/mdoege/newsfeed/
DISTNAME=	NewsFeed-${DISTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	RSS/RDF/Atom reader and aggregator

DEPRECATED=	Depends on net/py-timeoutsocket, which is DEPRECATED
EXPIRATION_DATE=	2011-10-31

RUN_DEPENDS=	py*-tkinter>=0:${PORTSDIR}/x11-toolkits/py-tkinter \
		py*-feedparser>=0:${PORTSDIR}/textproc/py-feedparser \
		py*-feedfinder>=0:${PORTSDIR}/www/py-feedfinder \
		py*-timeoutsocket>=0:${PORTSDIR}/net/py-timeoutsocket

USE_PYTHON=	yes
USE_TK=		yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	NewsFeed

post-patch:
	@${REINPLACE_CMD} -e '/py_modules=/s|,.*|],|;/sounds/s|d.*|)|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|rssfinder|feedfinder|;s|rssparser|feedparser|'\
		${WRKSRC}/newsfeed.py

.include <bsd.port.mk>
