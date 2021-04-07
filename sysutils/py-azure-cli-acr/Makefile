PORTNAME=	azure-cli-acr
PORTVERSION=	2.2.9
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools ACR Command Module

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-mgmt-storage>=3.3.0:devel/py-azure-mgmt-storage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-containerregistry>=2.8.0:devel/py-azure-mgmt-containerregistry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-storage-blob>=1.3.1:devel/py-azure-storage-blob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=0:sysutils/py-azure-cli-core@${PY_FLAVOR}

USES=		azurepy python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
