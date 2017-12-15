# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oauth2
DISTVERSION=	1.9.0.post1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python library for OAuth version 1.0

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httplib2>0:www/py-httplib2@${FLAVOR}
TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${FLAVOR}

OPTIONS_DEFINE=		TESTS
TESTS_DESC=		Install test suite requirements
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
