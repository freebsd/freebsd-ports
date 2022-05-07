PORTNAME=	pynauty
DISTVERSION=	1.1.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Isomorphism testing and automorphisms of graphs

LICENSE=	GPLv3

BUILD_DEPENDS=	gmake:devel/gmake
TEST_DEPENDS=	pytest:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+ shebangfix
USE_PYTHON=	distutils autoplist

SHEBANG_FILES=	src/pynauty/tests/test_minimal.py

BINARY_ALIAS=	make=${GMAKE} python3=${PYTHON_CMD}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pynauty/nautywrap*.so

do-test: install
	@cd ${WRKSRC} && pytest

.include <bsd.port.mk>
