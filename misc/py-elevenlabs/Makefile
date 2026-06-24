PORTNAME=	elevenlabs
DISTVERSION=	2.54.0
CATEGORIES=	misc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Official Python SDK for ElevenLabs text-to-speech platform
WWW=		https://github.com/elevenlabs/elevenlabs-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx>=0.21.2:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.9.2:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-core>=2.18.2:devel/py-pydantic-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=11.0:devel/py-websockets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
