PORTNAME=	ansible-compat
PORTVERSION=	4.1.2
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Ansible compatibility goodies
WWW=		https://github.com/ansible-community/ansible-compat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7.0.0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansible-core>=2.12:sysutils/py-ansible-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}subprocess-tee>=0.4.1:devel/py-subprocess-tee@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.6.0:devel/py-jsonschema@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip-tools>0:devel/py-pip-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=7.2.0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-plus>0:devel/py-pytest-plus@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	LC_ALL=C.UTF-8 PYTHONPATH=${WRKSRC}/src TMPDIR=${WRKDIR}/

NO_ARCH=	yes

.include <bsd.port.mk>
