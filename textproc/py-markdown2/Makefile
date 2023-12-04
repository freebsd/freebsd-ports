PORTNAME=	markdown2
PORTVERSION=	2.4.11
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Fast and complete Python implementation of Markdown
WWW=		https://github.com/trentm/python-markdown2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	autoplist concurrent distutils

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

OPTIONS_DEFINE=		SYNTAX WAVEDROM
OPTIONS_DEFAULT=	SYNTAX WAVEDROM

SYNTAX_DESC=		Code syntax highlighting support
WAVEDROM_DESC=		WaveDrom support

SYNTAX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=2.7.3:textproc/py-pygments@${PY_FLAVOR}
WAVEDROM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wavedrom>0:textproc/py-wavedrom@${PY_FLAVOR}

# One test (= markdown2/tm/issue52_hang) always results in an error which
# is a known failure.
do-test:
	cd ${WRKSRC}/test && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} test.py

.include <bsd.port.mk>
