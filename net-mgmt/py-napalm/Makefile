# $FreeBSD$

PORTNAME=	napalm
DISTVERSION=	2.4.0
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Net Automation and Progr. Abstraction Layer with Multivendor support

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textfsm>0:textproc/py-textfsm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}junos-eznc>=2.2.0:net-mgmt/py-junos-eznc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netmiko>=2.3.0:security/py-netmiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.4.2:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nxapi-plumbing>=0.5.2:net-mgmt/py-nxapi-plumbing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyeapi>=0.8.2:net-mgmt/py-pyeapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyIOSXR>=0.53:net-mgmt/py-pyIOSXR@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scp>0:security/py-scp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.11.3:devel/py-cffi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|==|>=|' ${WRKSRC}/requirements.txt

.include <bsd.port.mk>
