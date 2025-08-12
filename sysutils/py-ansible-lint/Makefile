PORTNAME=	ansible-lint
PORTVERSION=	6.17.1
PORTREVISION=	2
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Checks playbooks for sub-optimal practices and behaviour
WWW=		https://github.com/willthames/ansible-lint

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansible-core>=2.12.0:sysutils/py-ansible-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ansible-compat>=4.0.5:sysutils/py-ansible-compat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}black>=22.8.0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=3.3.0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.10.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=0.10.3:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=12.0.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.17.0:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}subprocess-tee>=0.4.1:devel/py-subprocess-tee@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcmatch>=8.1.2:textproc/py-wcmatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.4.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yamllint>=1.30.0:devel/py-yamllint@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7.0.5:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage_enable_subprocess>=0:devel/py-coverage_enable_subprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=6.4.4:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=0:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		pylint${PYTHON_PKGNAMESUFFIX}>=0:devel/pylint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=7.2.2:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-plus>=0.2:devel/py-pytest-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=2.1.0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.17.31:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml.clib>=0:devel/py-ruamel.yaml.clib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spdx-tools>=0.7.1:misc/py-spdx-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-jsonschema>=0:devel/py-types-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-pyyaml>=0:devel/py-types-pyyaml@${PY_FLAVOR} \
		bash:shells/bash

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ENV=	LC_ALL=C.UTF-8 PYTHONPATH=${WRKSRC}/src TMPDIR=${WRKDIR}/
NO_ARCH=	yes

.include <bsd.port.mk>
