# $FreeBSD$

PORTNAME=	azure-cli-dls
PORTVERSION=	0.1.9
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools Data Lake Store Command Module

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-mgmt-datalake-store>=0.5.0:devel/py-azure-mgmt-datalake-store@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-datalake-store>=0.0.39:devel/py-azure-datalake-store@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=0:sysutils/py-azure-cli-core@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
