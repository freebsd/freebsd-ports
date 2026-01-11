PORTNAME=	polars
DISTVERSIONPREFIX=	py-
DISTVERSION=	1.36.1
CATEGORIES=	misc
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Blazingly fast DataFrame library
WWW=		https://github.com/pola-rs/polars

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}altair>=5.4.0:graphics/py-altair@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}
.for runtime in compat 32 64 # same as flavors in misc/py-polars-runtime
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}polars-runtime-${runtime}>0:misc/py-polars-runtime@${runtime}
.endfor

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	pola-rs

WRKSRC_SUBDIR=	py-polars

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${CARGO_WRKSRC}/tests

BINARY_ALIAS=	python3=${PYTHON_CMD}

NO_ARCH=	yes

PORTSCOUT=	limit:^py-

.include <bsd.port.mk>
