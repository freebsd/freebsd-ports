PORTNAME=	fsph
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to quickly compute series of complex spherical harmonics
WWW=		https://fsph.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY}
#		${PYTHON_PKGNAMEPREFIX}tensorflow>0:science/py-tensorflow@${PY_FLAVOR} # tensorflow is an optional dependency that is currently broken: https://github.com/glotzerlab/fsph/issues/6
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		compiler:c++14-lang localbase python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	glotzerlab

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

CONFLICTS_BUILD=	${PYTHON_PKGNAMEPREFIX}-tensorflow

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/fsph/_fsph${PYTHON_EXT_SUFFIX}.so
		#${STAGEDIR}${PYTHON_SITELIBDIR}/fsph/_tf_ops${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
