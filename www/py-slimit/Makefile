# $FreeBSD$

PORTNAME=	slimit
PORTVERSION=	0.8.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	melvyn@magemana.nl
COMMENT=	JavaScript minifier written in Python

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=3.4:${PORTSDIR}/devel/py-ply
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=3.4:${PORTSDIR}/devel/py-ply

USES=			zip
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

# Maintainer: Reminder to keep testing python 3.x compatibility.
.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 300
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six
pre-build:
	@cd ${WRKSRC} && 2to3-${PYTHON_VER} -w src
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
