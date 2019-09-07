# $FreeBSD$

PORTNAME=	azure-cli-dms
PORTVERSION=	0.1.4
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools for the Data Migration Service (DMS) Command Module

LICENSE=	MIT

DEPRECATED=	Incorporated into azure-cli package
EXPIRATION_DATE=2019-09-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-mgmt-datamigration>=0.1.0:devel/py-azure-mgmt-datamigration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=0:sysutils/py-azure-cli-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
