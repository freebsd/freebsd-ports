PORTNAME=	google-cloud-testutils
DISTVERSION=	1.4.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Common tools used to test Python client libraries for Google APIs
WWW=		https://github.com/googleapis/python-test-utils

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7.0.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=0.4.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=19.0:devel/py-packaging@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}test-utils>0:devel/py-test-utils@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest # 10 tests fail, see https://github.com/googleapis/python-test-utils/issues/168

NO_ARCH=	yes

.include <bsd.port.mk>
