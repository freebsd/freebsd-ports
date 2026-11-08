PORTNAME=	http-sf
DISTVERSION=	1.3.1
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test
TEST_ARGS=	--disable-plugin-autoload
TEST_ARGS+=	--ignore=test_compat_full.py # see https://github.com/mnot/http-sf/issues/32

NO_ARCH=	yes

# tests as of 1.3.1: 25 passed in 0.04s

.include <bsd.port.mk>
