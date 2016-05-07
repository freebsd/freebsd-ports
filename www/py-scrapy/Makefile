# Created by: Qing Feng <qingfeng@douban.com>
# $FreeBSD$

PORTNAME=	Scrapy
PORTVERSION=	0.22.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	High level scraping and web crawling framework

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}w3lib>=1.2:www/py-w3lib \
		${PYTHON_PKGNAMEPREFIX}cssselect>=0.9:www/py-cssselect \
		${PYTHON_PKGNAMEPREFIX}queuelib>=1.2.2:sysutils/py-queuelib

USES=		python:2 twisted:run,web
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	SSL
OPTIONS_DEFAULT=SSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl
.endif

.include <bsd.port.mk>
