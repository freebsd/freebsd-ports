PORTNAME=	starlette
PORTVERSION=	0.47.3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight ASGI framework/toolkit
WWW=		https://www.starlette.io/ \
		https://github.com/Kludex/starlette

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.6.2<5:devel/py-anyio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	FULL
OPTIONS_DEFAULT=FULL
FULL_DESC=	Full dependencies

FULL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}itsdangerous>=0:security/py-itsdangerous@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-multipart>=0.0.18:www/py-python-multipart@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}httpx>=0.27.0<0.29.0:www/py-httpx@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.10.0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
