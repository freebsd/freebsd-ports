PORTNAME=	pyrfr
DISTVERSION=	0.9.0
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for the extensible C++ library for random forests
WWW=		https://github.com/automl/random_forest_run

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		swig:devel/swig \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	pep517 autoplist pytest

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/pyrfr/_regression${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/pyrfr/_util${PYTHON_TAG}.so

.include <bsd.port.mk>
