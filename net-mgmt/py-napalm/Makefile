# $FreeBSD$

PORTNAME=	napalm
DISTVERSION=	2.3.0
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	Net Automation and Progr. Abstraction Layer with Multivendor support

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jtextfsm>0:textproc/py-jtextfsm@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}junos-eznc>=2.1.5:net-mgmt/py-junos-eznc@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netmiko>=1.4.3:security/py-netmiko@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyeapi>0:net-mgmt/py-pyeapi@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyIOSXR>=0.51:net-mgmt/py-pyIOSXR@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynxos>0:net-mgmt/py-pynxos@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scp>0:security/py-scp@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
