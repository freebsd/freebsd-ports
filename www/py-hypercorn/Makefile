PORTNAME=	hypercorn
PORTVERSION=	0.18.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ASGI Server based on Hyper libraries and inspired by Gunicorn
WWW=		https://hypercorn.readthedocs.io/en/latest/ \
		https://github.com/pgjones/hypercorn

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PY_EXCEPTIONGROUP} \
		${PYTHON_PKGNAMEPREFIX}h11>=0:net/py-h11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h2>=4.1.0:www/py-h2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}priority>=0:www/py-priority@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}wsproto>=0.14.0:net/py-wsproto@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-trio>=0:devel/py-pytest-trio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio>=0:net/py-trio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

OPTIONS_DEFINE=	H3 TRIO UVLOOP
H3_DESC=	HTTP/3 support
TRIO_DESC=	trio worker support
UVLOOP_DESC=	uvloop worker support

H3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}aioquic>=0.9.0<1.0:www/py-aioquic@${PY_FLAVOR}
TRIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}trio>=0.22.0:net/py-trio@${PY_FLAVOR}
UVLOOP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uvloop>=0:devel/py-uvloop@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}taskgroup>=0:devel/py-taskgroup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
