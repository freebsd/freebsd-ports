PORTNAME=	scrapy
DISTVERSION=	2.13.3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	High level scraping and web crawling framework
WWW=		https://scrapy.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}hatchling>=1.27.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=21.7.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=37.0.0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssselect>=0.9.1:www/py-cssselect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7.1:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itemloaders>=1.0.1:devel/py-itemloaders@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsel>=1.5.0:textproc/py-parsel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=22.0.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}queuelib>=1.4.2:sysutils/py-queuelib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service-identity>=18.1.0:security/py-service-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}w3lib>=1.17.0:www/py-w3lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=5.1.0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protego>=0.1.15:www/py-protego@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydispatcher>=2.0.5:devel/py-pydispatcher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itemadapter>=0.1.0:devel/py-itemadapter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>=4.6.0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tldextract>0:dns/py-tldextract@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

.include <bsd.port.mk>
