# $FreeBSD$

PORTNAME=	borgmatic
PORTVERSION=	1.3.26
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Wrapper script for Borg backup software

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}borgbackup>=0:archivers/py-borgbackup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pykwalify>=0:textproc/py-pykwalify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0:devel/py-ruamel.yaml@${PY_FLAVOR}

USES=		python:3.6
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	@cd ${WRKSRC} && \
	  ${REINPLACE_CMD} -e 's|/etc/borgmatic|${PREFIX}/etc/borgmatic|g' \
		borgmatic/commands/borgmatic.py \
		borgmatic/commands/convert_config.py \
		borgmatic/commands/generate_config.py \
		borgmatic/config/collect.py \
		borgmatic/config/convert.py \
		borgmatic/config/schema.yaml \
		tests/unit/config/test_collect.py

.include <bsd.port.mk>
