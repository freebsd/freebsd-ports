PORTNAME=	toon-format
DISTVERSION=	1.2.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	lazeraman@gmail.com
COMMENT=	Token-oriented object notation for LLM prompts
WWW=		https://github.com/toon-format/toon-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0:devel/py-uv-build@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	PYDANTIC
PYDANTIC_DESC=	pydantic support

PYDANTIC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0:devel/py-pydantic2@${PY_FLAVOR}

.include <bsd.port.mk>
