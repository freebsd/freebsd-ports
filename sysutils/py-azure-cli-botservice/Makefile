# $FreeBSD$

PORTNAME=	azure-cli-botservice
PORTVERSION=	0.1.7
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools Bot Services Command Module

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-mgmt-botservice>=0.1.0:devel/py-azure-mgmt-botservice@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-web>=0.40.0:devel/py-azure-mgmt-web@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=0:sysutils/py-azure-cli-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
