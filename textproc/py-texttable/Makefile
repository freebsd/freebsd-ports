# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	texttable
PORTVERSION=	1.0.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Module for creating simple ASCII tables

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov

USES?=	python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && pytest -v --cov-report=term-missing --cov=texttable tests.py

.include <bsd.port.mk>
