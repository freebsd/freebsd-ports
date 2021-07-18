# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	hypercorn
PORTVERSION=	0.11.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Hypercorn-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ASGI Server based on Hyper libraries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h11>=0:net/py-h11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h2>=3.1.0:www/py-h2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}priority>=0:www/py-priority@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wsproto>=0.14.0:net/py-wsproto@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-trio>=0:devel/py-pytest-trio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio>=0:net/py-trio@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	H3 TRIO UVLOOP
H3_DESC=	HTTP/3 support
TRIO_DESC=	trio worker support
UVLOOP_DESC=	uvloop worker support

H3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}aioquic>=0.9.0<1.0:www/py-aioquic@${PY_FLAVOR}
TRIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}trio>=0.11.0:net/py-trio@${PY_FLAVOR}
UVLOOP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uvloop>=0:devel/py-uvloop@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

do-test:
	cd ${WRKSRC} && ${SETENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.post.mk>
