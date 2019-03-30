# $FreeBSD$

PORTNAME=	azure-cli-relay
PORTVERSION=	0.1.4
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools Relay Command Module

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-mgmt-relay>=0.1.0:devel/py-azure-mgmt-relay@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=0:sysutils/py-azure-cli-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
