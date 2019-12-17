# $FreeBSD$

PORTNAME=	slimit
PORTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JavaScript minifier written in Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=3.4:devel/py-ply@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=3.4:devel/py-ply@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

# Maintainer: Reminder to keep testing python 3.x compatibility.
.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 3000
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
pre-build:
	@cd ${WRKSRC} && 2to3-${PYTHON_VER} -w src
.endif

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
