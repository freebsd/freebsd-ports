PORTNAME=	yara-python
PORTVERSION=	4.5.5
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python bindings for yara
WWW=		https://virustotal.github.io/yara/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}yara-python-dex

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libyara.so:security/yara

USE_GITHUB=	yes
GH_ACCOUNT=	VirusTotal

USES=		cpe localbase python
CPE_VENDOR=	virustotal
USE_PYTHON=	pep517 autoplist
# XXX could not figure out how to pass --dynamic-linking as setup.py build args
#PEP517_BUILD_CONFIG_SETTING=	--dynamic-linking

DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD} tests.py
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_TARGET=	# empty

.include <bsd.port.mk>
