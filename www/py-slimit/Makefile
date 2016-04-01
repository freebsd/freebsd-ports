# $FreeBSD$

PORTNAME=	slimit
PORTVERSION=	0.8.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	melvyn@magemana.nl
COMMENT=	JavaScript minifier written in Python

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=3.4:devel/py-ply
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=3.4:devel/py-ply

USES=		python:2 zip
USE_PYTHON=	distutils autoplist

# Maintainer: Reminder to keep testing python 3.x compatibility.
.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 3000
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six
pre-build:
	@cd ${WRKSRC} && 2to3-${PYTHON_VER} -w src
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
