# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	turses
PORTVERSION=	0.2.19
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python Twitter client for the console

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oauth2>0:${PORTSDIR}/net/py-oauth2 \
		${PYTHON_PKGNAMEPREFIX}urwid>0:${PORTSDIR}/devel/py-urwid \
		${PYTHON_PKGNAMEPREFIX}tweepy>=2.1:${PORTSDIR}/net/py-tweepy

TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}nose>0:${PORTSDIR}/devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Install tools for unit tests
OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.options.mk>

USE_PYTHON=		-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS:=	${TEST_DEPENDS}
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
