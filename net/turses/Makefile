# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	turses
PORTVERSION=	0.2.22
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python Twitter client for the console

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oauth2>0:${PORTSDIR}/net/py-oauth2 \
		${PYTHON_PKGNAMEPREFIX}urwid>0:${PORTSDIR}/devel/py-urwid \
		${PYTHON_PKGNAMEPREFIX}tweepy>=2.2:${PORTSDIR}/net/py-tweepy

TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}nose>0:${PORTSDIR}/devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Install tools for unit tests
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

USES=		python:2
USE_PYTHON=	distutils autoplist

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
