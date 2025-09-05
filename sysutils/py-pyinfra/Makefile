PORTNAME=	pyinfra
DISTVERSION=	3.5
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Automates infrastructure using Python
WWW=		https://pyinfra.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>2:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=1.6<2:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>=1.5:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>2<4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=16.1:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.7<4:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>2<3:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pywinrm>0:security/py-pywinrm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typeguard>0:devel/py-typeguard@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>6:devel/py-pyyaml@${PY_FLAVOR}

USES=		pytest python
USE_PYTHON=	autoplist pep517

# Most of the ignored tests fail because docker is missing.
# The *_ensure_newline_* ones fail when pyinfra is not installed first.
PYTEST_IGNORED_TESTS=	test_int_docker_install_package_ubuntu \
			test_e2e_ssh_sudo_password \
			test_int_local_file_no_changes \
			test_int_local_directory_no_changes \
			test_int_local_link_no_changes \
			test_int_local_line_no_changes \
			test_int_local_line_ensure_newline_true \
			test_int_local_line_ensure_newline_false

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>3.6:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
