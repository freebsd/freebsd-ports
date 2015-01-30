# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bleach
PORTVERSION=	1.4.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Easy whitelist-based HTML-sanitizing tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}html5lib>=0.999:${PORTSDIR}/www/py-html5lib
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}html5lib>=0.999:${PORTSDIR}/www/py-html5lib \
		${PYTHON_PKGNAMEPREFIX}nose>=1.3:${PORTSDIR}/devel/py-nose

OPTIONS_DEFINE=	TESTS

TESTS_DESC=		Install test suite requirements
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
