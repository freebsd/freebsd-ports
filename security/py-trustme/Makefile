PORTNAME=	trustme
PORTVERSION=	0.8.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Top quality TLS certs while you wait, for the discerning tester

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.APACHE2
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>=0:security/py-service_identity@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes
TEST_ENV=	PYTHONPATH="${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}"

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
