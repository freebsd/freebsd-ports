# $FreeBSD$

PORTNAME=	wtf-peewee
PORTVERSION=	3.0.0
CATEGORIES=	textproc devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Bridge between peewee models and wtforms

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}peewee>=0:databases/py-peewee@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wtforms>=0:textproc/py-wtforms@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
