PORTNAME=	netmiko
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1
PORTREVISION=	1
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Multi-vendor library to simplify SSH connections to network devices

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=2.4.3:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scp>=0.13.2:security/py-scp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textfsm>0:textproc/py-textfsm@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.1.2:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	ktbyers

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -s tests/test_import_netmiko.py

.include <bsd.port.mk>
