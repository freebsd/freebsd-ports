# $FreeBSD$

PORTNAME=	azure-cli-batch
PORTVERSION=	4.0.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools Batch Command Module

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-mgmt-batch>=6.0.0:devel/py-azure-mgmt-batch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-batch>=6.0.0:devel/py-azure-batch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=0:sysutils/py-azure-cli-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-keyvault>=1.1.0:devel/py-azure-mgmt-keyvault@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
