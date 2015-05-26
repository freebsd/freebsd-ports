# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gandi.cli
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Gandi command line interface

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}click>0:${PORTSDIR}/devel/py-click \
		${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}ipy>0:${PORTSDIR}/net-mgmt/py-ipy
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:${PORTSDIR}/devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}coverage>0:${PORTSDIR}/devel/py-coverage

OPTIONS_DEFINE=		TESTS
TESTS_DESC=		Install test suite requirements
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
