PORTNAME=	Scrapy
DISTVERSION=	2.5.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	High level scraping and web crawling framework
WWW=		https://scrapy.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssselect>=0.9.1:www/py-cssselect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itemloaders>=1.0.1:devel/py-itemloaders@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsel>=1.5:textproc/py-parsel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=16.2.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}queuelib>=1.4.2:sysutils/py-queuelib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service-identity>=16.0.0:security/py-service-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}w3lib>=1.17.0:www/py-w3lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=4.1.3:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protego>=0.1.15:www/py-protego@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itemadapter>=0.1.0:devel/py-itemadapter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.5.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydispatcher>=2.0.5:devel/py-pydispatcher@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent cryptography distutils

NO_ARCH=	yes

# Remove experimental HTTP/2 support, issues with Twisted and h2
post-extract:
	@${RM} -r ${WRKSRC}/scrapy/core/http2
	@${RM}  ${WRKSRC}/scrapy/core/downloader/handlers/http2.py

.include <bsd.port.mk>
