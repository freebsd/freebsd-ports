PORTNAME=	netmiko
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.1
CATEGORIES=	security net-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Multi-vendor library to simplify SSH connections to network devices

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ntc-templates>=2.0.0:textproc/py-ntc-templates@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.7.2:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scp>=0.13.2:security/py-scp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>0:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textfsm>=1.1.2:textproc/py-textfsm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.3:devel/py-yaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils
USE_GITHUB=	yes
GH_ACCOUNT=	ktbyers

NO_ARCH=	yes

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -s tests/test_import_netmiko.py

.include <bsd.port.mk>
