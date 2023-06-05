PORTNAME=	ufolib2
PORTVERSION=	0.15.0
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ufoLib2-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	UFO font processing library
WWW=		https://github.com/fonttools/ufoLib2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=45:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=6.2:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=22.1.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.0.0:print/py-fonttools@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	CONVERTERS JSON LXML MSGPACK
CONVERTERS_DESC=Converters support
LXML_DESC=	XML support
MSGPACK_DESC=	MessagePack support

CONVERTERS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cattrs>=1.10.0:devel/py-cattrs@${PY_FLAVOR}
JSON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cattrs>=22.2.0:devel/py-cattrs@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}orjson>=0:devel/py-orjson@${PY_FLAVOR}
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}
MSGPACK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cattrs>=22.2.0:devel/py-cattrs@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}msgpack>=0:devel/py-msgpack@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
