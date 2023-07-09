PORTNAME=	pysaml2
PORTVERSION=	7.4.2
CATEGORIES=	security devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python implementation of SAML Version 2
WWW=		https://github.com/IdentityPython/pysaml2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=3.1,1:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0,1:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0,1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmlschema>=1.2.1:textproc/py-xmlschema@${PY_FLAVOR} \
		xmlsec1:security/xmlsec1
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>=0:devel/py-responses@${PY_FLAVOR}

USES=		cpe python:3.9+ shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CPE_VENDOR=	pysaml2_project

SHEBANG_FILES=	src/saml2/authn_context/timesync.py

OPTIONS_DEFINE=	S2REPOZE
S2REPOZE_DESC=	Repoze module support

S2REPOZE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Paste>=0:www/py-paste@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}repoze.who>=0:devel/py-repoze.who@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
