# Created by: Qing Feng <qingfeng@douban.com>

PORTNAME=	Scrapy
DISTVERSION=	2.5.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	High level scraping and web crawling framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=2.0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssselect>=0.9.1:www/py-cssselect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itemloaders>=1.0.1:devel/py-itemloaders@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsel>=1.5:textproc/py-parsel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=16.2.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}queuelib>=1.4.2:sysutils/py-queuelib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>=16.0.0:security/py-service_identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}w3lib>=1.17.0:www/py-w3lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=4.1.3:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protego>=0.1.15:www/py-protego@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itemadapter>=0.1.0:devel/py-itemadapter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.5.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydispatcher>=2.0.5:devel/py-pydispatcher@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

# Remove experimental HTTP/2 support, issues with Twisted and h2
post-extract:
	@${RM} -r ${WRKSRC}/scrapy/core/http2
	@${RM}  ${WRKSRC}/scrapy/core/downloader/handlers/http2.py

.include <bsd.port.mk>
