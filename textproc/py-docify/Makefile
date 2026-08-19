PORTNAME=	docify
PORTVERSION=	1.2.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Script to add docstrings to Python type stubs using reflection
WWW=		https://github.com/atoerien/docify

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libcst>=1.1.0:devel/py-libcst@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.66.4:misc/py-tqdm@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

SHEBANG_FILES=	docify.py

.include <bsd.port.mk>
