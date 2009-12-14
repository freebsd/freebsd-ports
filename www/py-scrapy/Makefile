# New ports collection makefile for:	py-scrapy
# Date created:				10 Jul 2009
# Whom:					Qing Feng <qingfeng@me.com>
#
# $FreeBSD$
#

PORTNAME=	Scrapy
PORTVERSION=	0.8
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://scrapy.org/releases/0.8/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	qingfeng@me.com
COMMENT=	A high level scraping and web crawling framework

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=8.2.0:${PORTSDIR}/devel/py-twisted \
		${PYTHON_PKGNAMEPREFIX}libxml2>=2.7.6:${PORTSDIR}/textproc/py-libxml2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

post-extract:
	${REINPLACE_CMD} -e 's#Twisted>=2.5##g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
