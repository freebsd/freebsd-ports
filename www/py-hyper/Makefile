# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	hyper
DISTVERSION=	0.8.0.g20171217
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	HTTP/2 Client for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h2>=2.4:www/py-h2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hyperframe>=3.2:www/py-hyperframe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotlipy>=0.7.0:archivers/py-brotlipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986>=1.1.0,<2.0:www/py-rfc3986@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hpack>0:www/py-hpack@${PY_FLAVOR}

USES=		cpe python:3.6+
CPE_VENDOR=	python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	Lukasa
GH_TAGNAME=	18b629b

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -k 'not test_HTTPConnection_with_custom_context' test

.include <bsd.port.mk>
