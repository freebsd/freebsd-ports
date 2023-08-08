PORTNAME=	pystan
PORTVERSION=	2.19.0.0
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmm@tutanota.com
COMMENT=	Python interface for Stan
WWW=		https://github.com/stan-dev/pystan

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++14-lang python shebangfix
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 30900
# See PR 262797 - to be upgraded after the modernization of OCaml ports
BROKEN=		several build errors
.endif

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cython>0:lang/cython@${PY_FLAVOR}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cython>0:lang/cython@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

SHEBANG_FILES=	${WRKSRC}/pystan/stan/lib/stan_math/lib/upgrade-sundials.sh \
		${WRKSRC}/pystan/stan/lib/stan_math/hooks/pre-commit \
		${WRKSRC}/pystan/stan/lib/stan_math/runTests.py \

NO_ARCH=	yes
NO_ARCH_IGNORE=	_api.so _chains.so _misc.so

.include <bsd.port.post.mk>
