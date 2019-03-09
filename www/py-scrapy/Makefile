# Created by: Qing Feng <qingfeng@douban.com>
# $FreeBSD$

PORTNAME=	Scrapy
DISTVERSION=	1.6.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	High level scraping and web crawling framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=13.1.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}w3lib>=1.17.0:www/py-w3lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssselect>=0.9:www/py-cssselect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}queuelib>0:sysutils/py-queuelib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydispatcher>=2.0.5:devel/py-pydispatcher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>0:security/py-service_identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.5.2:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsel>=1.5:textproc/py-parsel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist

OPTIONS_DEFINE=		SSL
OPTIONS_DEFAULT=	SSL

SSL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR}

.include <bsd.port.mk>
