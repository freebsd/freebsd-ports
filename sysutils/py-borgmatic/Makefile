# $FreeBSD$

PORTNAME=	borgmatic
PORTVERSION=	1.3.1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Wrapper script for Borg backup software

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}borgbackup>=0:archivers/py-borgbackup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pykwalify>=0:textproc/py-pykwalify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0:devel/py-ruamel.yaml@${PY_FLAVOR}

USES=		python:3.6
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
