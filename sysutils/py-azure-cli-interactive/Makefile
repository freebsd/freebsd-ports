# $FreeBSD$

PORTNAME=	azure-cli-interactive
PORTVERSION=	0.4.5
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Interactive Shell

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-cli-core>=0:sysutils/py-azure-cli-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt_toolkit1>=1.0.15:devel/py-prompt_toolkit1@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
