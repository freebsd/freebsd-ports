# $FreeBSD$

PORTNAME=	azure-cli-lab
PORTVERSION=	0.1.7
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools DevTestLabs Command Module

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-mgmt-devtestlabs>=2.2.0:devel/py-azure-mgmt-devtestlabs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-graphrbac>=0.60.0:devel/py-azure-graphrbac@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=0:sysutils/py-azure-cli-core@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
