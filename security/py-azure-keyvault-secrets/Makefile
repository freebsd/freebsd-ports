# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	azure-keyvault-secrets
PORTVERSION=	4.3.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Key Vault Secrets Client Library for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-common>=1.1<2:www/py-azure-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-core>=1.7.0<2.0.0:devel/py-azure-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msrest>=0.6.21:net-mgmt/py-msrest@${PY_FLAVOR}

USES=		python:3.6+ zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
