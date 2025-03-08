PORTNAME=	pystan
PORTVERSION=	2.19.0.0
PORTREVISION=	3
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmm@tutanota.com
COMMENT=	Python interface for Stan
WWW=		https://github.com/stan-dev/pystan

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		several build errors
DEPRECATED=	Marked as BROKEN for years
EXPIRATION_DATE=2025-02-28

USES=		compiler:c++14-lang python shebangfix
USE_PYTHON=	autoplist distutils

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cython>0:lang/cython@${PY_FLAVOR}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cython>0:lang/cython@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

SHEBANG_FILES=	${WRKSRC}/pystan/stan/lib/stan_math/lib/upgrade-sundials.sh \
		${WRKSRC}/pystan/stan/lib/stan_math/hooks/pre-commit \
		${WRKSRC}/pystan/stan/lib/stan_math/runTests.py \

NO_ARCH=	yes
NO_ARCH_IGNORE=	_api.so _chains.so _misc.so

.include <bsd.port.mk>
