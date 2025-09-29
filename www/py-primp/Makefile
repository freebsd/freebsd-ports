PORTNAME=	primp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.0
CATEGORIES=	www
#MASTER_SITES=	PYPI # conflicts with USES=cargo
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance HTTP client with advanced web browser impersonation
WWW=		https://github.com/deedy5/primp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.5:devel/py-maturin@${PY_FLAVOR} \
		git:devel/git # git shouldn't be needed here but it is expected
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.25.3:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		cargo cmake:indirect llvm perl5 pkgconfig python
USE_PYTHON=	pep517 autoplist pytest
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	deedy5

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

BINARY_ALIAS=	cc=${FILESDIR}/cc

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

# tests as of 0.15.0:
# Results (32.59s):
#       21 passed
#        2 failed
#          - tests/test_defs.py:11 test_get_impersonate_firefox133
#          - tests/test_client.py:11 test_client_impersonate_chrome131

.include <bsd.port.mk>
