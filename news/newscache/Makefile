# New ports collection Makefile for:   newscache
# Date created:                23 February 2002
# Whom:                        Tilman Linneweh <freebsdports@arved.de>
#
# $FreeBSD$
#

PORTNAME=	newscache
PORTVERSION=	0.99.22
CATEGORIES=	news
MASTER_SITES=	http://members.aon.at/hstraub/linux/newscache/ \
		http://www.infosys.tuwien.ac.at/NewsCache/download/
DISTNAME=	NewsCache-${PORTVERSION}

MAINTAINER=	freebsdports@arved.de

WRKSRC=		${WRKDIR}/NewsCache

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GCC=	2.95

MAN5=	newscache.conf.5
MAN8=	NewsCache.8 NewsCacheClean.8 updatenews.8

.include <bsd.port.mk>
