# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	texttable
PORTVERSION=	1.2.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Module for creating simple ASCII tables

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cjkwrap>=0:textproc/py-cjkwrap@${FLAVOR}

CJKWRAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cjkwrap>=0:textproc/py-cjkwrap@${FLAVOR}

USES=	python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

OPTIONS_DEFINE=	CJKWRAP

CJKWRAP_DESC=	Text Wrapping with better CJK text support

do-test:
	@cd ${WRKSRC} && pytest -v --cov-report=term-missing --cov=texttable tests.py

.include <bsd.port.mk>
