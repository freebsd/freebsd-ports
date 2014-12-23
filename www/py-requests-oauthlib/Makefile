# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	requests-oauthlib
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	OAuthlib authentication support for Requests

LICENSE=	ISCL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oauthlib>=0.6.2:${PORTSDIR}/security/py-oauthlib \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:${PORTSDIR}/www/py-requests
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto

OPTIONS_DEFINE=	TESTS

TESTS_DESC=		Install test suite dependencies
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
