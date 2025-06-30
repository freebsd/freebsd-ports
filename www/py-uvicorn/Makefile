PORTNAME=	uvicorn
PORTVERSION=	0.35.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightning-fast ASGI server
WWW=		https://www.uvicorn.org/ \
		https://github.com/encode/uvicorn

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h11>=0.8:net/py-h11@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CPE_VENDOR=	encode

OPTIONS_DEFINE=	STANDARD
STANDARD_DESC=	Standard extra requirements

STANDARD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httptools>=0.6.3:www/py-httptools@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-dotenv>=0.13:www/py-python-dotenv@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}uvloop>=0.15.1:devel/py-uvloop@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}watchfiles>=0.13:devel/py-watchfiles@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}websockets>=10.4:devel/py-websockets@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
