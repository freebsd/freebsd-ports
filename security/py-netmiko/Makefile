PORTNAME=	netmiko
DISTVERSIONPREFIX=	v
DISTVERSION=	4.6.0
CATEGORIES=	security net-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Multi-vendor library to simplify SSH connections to network devices
WWW=		https://github.com/ktbyers/netmiko

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ntc-templates>=3.1.0:textproc/py-ntc-templates@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.9.5:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=3.3:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.8:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.17:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scp>=0.13.6:security/py-scp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textfsm>=1.1.3:textproc/py-textfsm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.1:devel/py-pyyaml@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517 pytest
USE_GITHUB=	yes
GH_ACCOUNT=	ktbyers
SHEBANG_FILES=	netmiko/cli_tools/netmiko_bulk_encrypt.py \
		netmiko/cli_tools/netmiko_cfg.py \
		netmiko/cli_tools/netmiko_encrypt.py \
		netmiko/cli_tools/netmiko_grep.py \
		netmiko/cli_tools/netmiko_show.py

TEST_ARGS=	tests/test_import_netmiko.py

NO_ARCH=	yes

.include <bsd.port.mk>
