# $FreeBSD$

PORTNAME=	azure-cli-keyvault
PORTVERSION=	2.2.12
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools Keyvault Command Module

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-mgmt-keyvault>=1.1.0:devel/py-azure-mgmt-keyvault@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-keyvault>=1.1.0:devel/py-azure-keyvault@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-graphrbac>=0.53.0:devel/py-azure-graphrbac@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=0:sysutils/py-azure-cli-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
