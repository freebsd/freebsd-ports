# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	uvicorn
PORTVERSION=	0.18.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightning-fast ASGI server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h11>=0.8:net/py-h11@${PY_FLAVOR}

USES=		cpe python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CPE_VENDOR=	encode

OPTIONS_DEFINE=	STANDARD
STANDARD_DESC=	Standard extra requirements

STANDARD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httptools>=0.4.0:www/py-httptools@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-dotenv>=0.13:www/py-python-dotenv@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}yaml>=5.1:devel/py-yaml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}uvloop>=0.14.0:devel/py-uvloop@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}watchfiles>=0.13:devel/py-watchfiles@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}websockets>=10.0:devel/py-websockets@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
