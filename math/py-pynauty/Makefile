PORTNAME=	pynauty
DISTVERSION=	1.1.2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Isomorphism testing and automorphisms of graphs
WWW=		https://github.com/pdobsan/pynauty

LICENSE=	GPLv3

BUILD_DEPENDS=	gmake:devel/gmake
TEST_DEPENDS=	pytest:devel/py-pytest@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	distutils autoplist

SHEBANG_FILES=	src/pynauty/tests/test_minimal.py

BINARY_ALIAS=	make=${GMAKE} python3=${PYTHON_CMD}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pynauty/nautywrap*.so

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest

.include <bsd.port.mk>
