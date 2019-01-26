# $FreeBSD$

PORTNAME=	azure-cli-iot
PORTVERSION=	0.3.4
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools IoT Command Module

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-mgmt-iothub>=0.7.0:devel/py-azure-mgmt-iothub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-iothubprovisioningservices>=0.2.0:devel/py-azure-mgmt-iothubprovisioningservices@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=0:sysutils/py-azure-cli-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
