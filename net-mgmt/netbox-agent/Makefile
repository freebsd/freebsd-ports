PORTNAME=	netbox-agent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2-77
DISTVERSIONSUFFIX=-g6ae055c
CATEGORIES=	net-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kiwi@oav.net
COMMENT=	Agent for the Netbox network automation
WWW=		https://github.com/KlaraSystems/netbox-agent

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/ipmitool:sysutils/ipmitool \
		${LOCALBASE}/sbin/dmidecode:sysutils/dmidecode \
		${LOCALBASE}/sbin/lldpctl:net-mgmt/lldpd \
		${PYTHON_PKGNAMEPREFIX}distro>=1.8.0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonargparse>=3.11.2:devel/py-jsonargparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=1.0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces-plus>=0.11:net/py-netifaces-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.9.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynetbox>=7:net-mgmt/py-pynetbox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-slugify>=8.0.1:textproc/py-python-slugify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sysctl>=0.3.0:devel/py-sysctl@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	KlaraSystems

USE_PYTHON=	autoplist distutils pytest

NO_ARCH=	yes

.include <bsd.port.mk>
