PORTNAME=	ansible-compat
PORTVERSION=	2.2.7
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Ansible compatibility goodies
WWW=		https://github.com/ansible-community/ansible-compat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=6.4.2:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}subprocess-tee>=0.3.5:devel/py-subprocess-tee@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.6.0:devel/py-jsonschema@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flaky>0:devel/py-flaky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip-tools>0:devel/py-pip-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>7.2.0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-plus>0:devel/py-pytest-plus@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist distutils pytest

NO_ARCH=	yes

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.mk>
