# Created by: René Ladan <rene@freebsd.org>
# $FreeBSD$

PORTNAME=	scandir
PORTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and featureful directory iterator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	autoplist concurrent distutils

USE_LOCALE=	en_US.UTF-8

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_scandir.so

do-test:
	${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${WRKSRC}/test/run_tests.py

.include <bsd.port.mk>
