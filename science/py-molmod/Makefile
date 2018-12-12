# $FreeBSD$

PORTNAME=	molmod
DISTVERSION=	1.4.4
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of molecular modelling tools for python

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		python shebangfix
SHEBANG_GLOB=	*.py
USE_PYTHON=	distutils cython cython_run autoplist

do-test: # Tests fail: https://github.com/molmod/molmod/issues/27
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} nosetests-${PYTHON_VER} -v molmod

.include <bsd.port.mk>
