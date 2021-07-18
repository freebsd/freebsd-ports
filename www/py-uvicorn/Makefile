# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	uvicorn
PORTVERSION=	0.14.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightning-fast ASGI server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7<8:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h11>=0.8:net/py-h11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httptools>=0.2.0<0.3:www/py-httptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=0.13:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.1:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvloop>=0.14.0:devel/py-uvloop@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=9.1:devel/py-websockets@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	WATCHGODRELOAD
WATCHGODRELOAD_DESC=	Reload automatically with watchgod

WATCHGODRELOAD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}watchgod>=0.6:devel/py-watchgod@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
