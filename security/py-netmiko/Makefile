PORTNAME=	netmiko
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.0
CATEGORIES=	security net-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Multi-vendor library to simplify SSH connections to network devices
WWW=		https://github.com/ktbyers/netmiko

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.3.2:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ntc-templates>=2.0.0:textproc/py-ntc-templates@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.9.5:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=3.3:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scp>=0.13.6:security/py-scp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textfsm>=1.1.3:textproc/py-textfsm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.3:devel/py-yaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517
USE_GITHUB=	yes
GH_ACCOUNT=	ktbyers
SHEBANG_FILES=	netmiko/cli_tools/netmiko_cfg.py \
		netmiko/cli_tools/netmiko_grep.py \
		netmiko/cli_tools/netmiko_show.py

NO_ARCH=	yes

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -s tests/test_import_netmiko.py

.include <bsd.port.mk>
