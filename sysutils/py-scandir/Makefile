# Created by: René Ladan <rene@freebsd.org>
# $FreeBSD$

PORTNAME=	scandir
PORTVERSION=	1.10.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Fast and featureful directory iterator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	benhoyt

USE_LOCALE=	en_US.UTF-8

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_scandir.so

do-test:
	${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${WRKSRC}/test/run_tests.py

.include <bsd.port.mk>
