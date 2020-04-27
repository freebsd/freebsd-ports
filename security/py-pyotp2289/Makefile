# Created by: Simeon Simeonov <sgs@pichove.org>
# $FreeBSD$

PORTNAME=	pyotp2289
PORTVERSION=	1.0.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sgs@pichove.org
COMMENT=	Pure Python implementation of RFC-2289 - "A One-Time Password System"

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v -o addopts=

.include <bsd.port.mk>
