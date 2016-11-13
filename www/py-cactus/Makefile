# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cactus
PORTVERSION=	3.0.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Cactus-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Static site generator for designers

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django16>0:www/py-django16 \
		${PYTHON_PKGNAMEPREFIX}markdown2>0:textproc/py-markdown2 \
		${PYTHON_PKGNAMEPREFIX}argparse>0:devel/py-argparse \
		${PYTHON_PKGNAMEPREFIX}boto>=2.4.1:devel/py-boto \
		${PYTHON_PKGNAMEPREFIX}tornado>=3.2:www/py-tornado \
		${PYTHON_PKGNAMEPREFIX}colorlog>0:devel/py-colorlog \
		${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama \
		${PYTHON_PKGNAMEPREFIX}django-markwhat>0:www/py-django-markwhat
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock

USES=		python:-2.7
USE_PYTHON=	autoplist concurrent distutils

OPTIONS_DEFINE=	TESTS

TESTS_DESC=	Install test suite requirements

TESTS_BUILD_DEPENDS=	${RUN_DEPENDS} \
			${TEST_DEPENDS}

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
