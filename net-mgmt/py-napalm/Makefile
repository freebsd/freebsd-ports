PORTNAME=	napalm
DISTVERSION=	5.2.0
CATEGORIES=	net-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Net Automation and Progr. Abstraction Layer with Multivendor support
WWW=		https://github.com/napalm-automation/napalm

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0.11.32:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.3.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textfsm>=1.1.3:textproc/py-textfsm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}junos-eznc>=2.7.4:net-mgmt/py-junos-eznc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ncclient>=0.6.16:net-mgmt/py-ncclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=1.3.0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netutils>=1.0.0:net-mgmt/py-netutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netmiko>=4.4.0:security/py-netmiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=3.5.0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ttp>=0.9.5:textproc/py-ttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ttp-templates>=0.3.7:textproc/py-ttp-templates@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.12.2:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyeapi>=1.0.2:net-mgmt/py-pyeapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.2:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ddt>=1.2.0:devel/py-ddt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest
USE_GITHUB=	yes
GH_ACCOUNT=	napalm-automation

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
