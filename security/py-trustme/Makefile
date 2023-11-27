PORTNAME=	trustme
PORTVERSION=	1.1.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Top quality TLS certs while you wait, for the discerning tester
WWW=		https://github.com/python-trio/trustme

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.APACHE2
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}idna>=0:dns/py-idna@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service-identity>=0:security/py-service-identity@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cryptography distutils pytest
NO_ARCH=	yes

.include <bsd.port.mk>
