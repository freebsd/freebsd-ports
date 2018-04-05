# $FreeBSD$

PORTNAME=	pyIOSXR
DISTVERSION=	0.52
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	Python API to interact with network devices running IOS-XR

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=3.2.4:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netmiko>=1.4.1:security/py-netmiko@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
