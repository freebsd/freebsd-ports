PORTNAME=	pytauri
DISTVERSION=	0.8.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tauri binding for Python through PyO3
WWW=		https://pytauri.github.io/pytauri/ \
		https://github.com/pytauri/pytauri

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.26:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydantic2>=2:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}anyio>=4:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=11.1:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.14:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=8:devel/py-importlib-metadata@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
