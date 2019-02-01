# $FreeBSD$

PORTNAME=	napalm
DISTVERSION=	2.3.3
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Net Automation and Progr. Abstraction Layer with Multivendor support

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textfsm>0:textproc/py-textfsm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}junos-eznc>=2.1.5:net-mgmt/py-junos-eznc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netmiko>=2.1.1:security/py-netmiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyeapi>0:net-mgmt/py-pyeapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyIOSXR>=0.53:net-mgmt/py-pyIOSXR@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynxos>=0.0.3:net-mgmt/py-pynxos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scp>0:security/py-scp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.11.3:devel/py-cffi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|==|>=|' ${WRKSRC}/requirements.txt

.include <bsd.port.mk>
