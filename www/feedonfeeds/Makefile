# Created by: ijliao
# $FreeBSD$

PORTNAME=	feedonfeeds
PORTVERSION=	0.5
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	wtp@bsdserwis.com
COMMENT=	Server side personal RSS (and Atom) aggregator

BROKEN_powerpc64=	Does not build

USES=		tar:tgz
PROJECTHOST=	feed-on-feeds
USE_PHP=	mysql xml zlib curl mbstring iconv
WANT_PHP_WEB=	yes
USE_MYSQL=	yes
NO_BUILD=	yes
NO_ARCH=	yes
DATADIR?=	${PREFIX}/www/data/feed-on-feeds
WRKSRC=		${WRKDIR}/${PROJECTHOST}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
