PORTNAME=	tweedledum
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
#PORTVERSION=	${DISTVERSION}-20260518
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for analysis, compilation, synthesis of quantum circuits
WWW=		https://github.com/boschmitt/tweedledum

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

#BROKEN_FreeBSD_14=	clang crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=265751

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build>=0.10:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.10:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nanobind>=2.12.0:devel/py-nanobind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		cmake:indirect ninja:build compiler:c++17-lang python
USE_PYTHON=	autoplist pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	boschmitt
GH_TAGNAME=	b30d175b1e5343ccefaa5762cd66a80980667bed

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/python/test

.include <bsd.port.mk>
