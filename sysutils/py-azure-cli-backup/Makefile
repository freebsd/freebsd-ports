# $FreeBSD$

PORTNAME=	azure-cli-backup
PORTVERSION=	1.2.4
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools Recovery Services Command Module

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-mgmt-recoveryservices>=0.1.1:devel/py-azure-mgmt-recoveryservices@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-recoveryservicesbackup>=0.1.2:devel/py-azure-mgmt-recoveryservicesbackup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=0:sysutils/py-azure-cli-core@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
