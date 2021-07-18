# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	starlette
PORTVERSION=	0.15.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight ASGI framework/toolkit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.0.0<4:devel/py-anyio@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	FULL
OPTIONS_DEFAULT=FULL
FULL_DESC=	Full dependencies

FULL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graphene>=0:devel/py-graphene@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}itsdangerous>=0:security/py-itsdangerous@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-multipart>=0:www/py-python-multipart@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

.include <bsd.port.mk>
