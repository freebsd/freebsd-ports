PORTNAME=	napalm
DISTVERSION=	4.0.0
CATEGORIES=	net-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Net Automation and Progr. Abstraction Layer with Multivendor support

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.3.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textfsm>=1.1.2:textproc/py-textfsm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}junos-eznc>=2.6.3:net-mgmt/py-junos-eznc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ncclient>0:net-mgmt/py-ncclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netutils>=1.0.0:net-mgmt/py-netutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netmiko>=4.0.0:security/py-netmiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.6.0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ttp>0:textproc/py-ttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ttp-templates>0:textproc/py-ttp-templates@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.3.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyeapi>=0.8.2:net-mgmt/py-pyeapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scp>0:security/py-scp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.11.3:devel/py-cffi@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.6.4:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ddt>=1.2.0:devel/py-ddt@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils concurrent autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	napalm-automation

NO_ARCH=	yes

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
