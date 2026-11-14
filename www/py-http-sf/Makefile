PORTNAME=	http-sf
DISTVERSION=	1.5.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for parsing and serializing HTTP Structured Fields (RFC 9651)
WWW=		https://github.com/mnot/http-sf

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test
TEST_ARGS=	--disable-plugin-autoload
TEST_ARGS+=	--ignore=test_compat_full.py # see https://github.com/mnot/http-sf/issues/32
TEST_ARGS+=	--deselect=test/test_offending_char.py::TestSuite::test_suite_errors # needs the test suite data missing from sdist

NO_ARCH=	yes

# tests as of 1.5.0: 313 passed, 1 deselected, 11235 subtests passed in 8.53s

.include <bsd.port.mk>
