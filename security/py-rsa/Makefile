# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rsa
PORTVERSION=	3.1.4
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Pure-Python RSA implementation

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1>=0.1.3:${PORTSDIR}/devel/py-asn1
TEST_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}unittest2>0:${PORTSDIR}/devel/py-unittest2 \
		${RUN_DEPENDS}

OPTIONS_DEFINE=	TESTS

TESTS_DESC=		Install tools for unit tests
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} run_tests.py

.include <bsd.port.mk>
