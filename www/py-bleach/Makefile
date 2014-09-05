# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bleach
PORTVERSION=	1.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Easy whitelist-based HTML-sanitizing tool for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}html5lib>=0.95:${PORTSDIR}/www/py-html5lib
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}html5lib>=0.95:${PORTSDIR}/www/py-html5lib \
		nosetests:${PORTSDIR}/devel/py-nose

OPTIONS_DEFINE=	TESTS

TESTS_DESC=		Install tools for test suite
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
