PORTNAME=	markdown2
PORTVERSION=	2.5.4
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Fast and complete Python implementation of Markdown
WWW=		https://github.com/trentm/python-markdown2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

OPTIONS_DEFINE=		LATEX SYNTAX WAVEDROM
OPTIONS_DEFAULT=	LATEX SYNTAX WAVEDROM

LATEX_DESC=		LaTeX to MathML conversion support
SYNTAX_DESC=		Code syntax highlighting support
WAVEDROM_DESC=		WaveDrom support

LATEX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}latex2mathml>=0:textproc/py-latex2mathml@${PY_FLAVOR}
SYNTAX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=2.7.3:textproc/py-pygments@${PY_FLAVOR}
WAVEDROM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wavedrom>0:textproc/py-wavedrom@${PY_FLAVOR}

# One test (= markdown2/tm/issue52_hang) always results in an error which
# is a known failure.
do-test:
	cd ${WRKSRC}/test && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} test.py

.include <bsd.port.mk>
