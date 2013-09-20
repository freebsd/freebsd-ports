# Created by: ijliao
# $FreeBSD$

PORTNAME=	feedonfeeds
PORTVERSION=	0.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wtp@bsdserwis.com
COMMENT=	Server side personal RSS (and Atom) aggregator

PROJECTHOST=	feed-on-feeds
USE_PHP=	mysql xml zlib curl mbstring iconv
WANT_PHP_WEB=	yes
USE_MYSQL=	yes
NO_BUILD=	yes
DATADIR?=	${PREFIX}/www/data/feed-on-feeds
WRKSRC=	${WRKDIR}/${PROJECTHOST}

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/ ${DATADIR}

.include <bsd.port.mk>
