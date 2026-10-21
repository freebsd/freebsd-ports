PORTNAME=	pyclipper
PORTVERSION=	1.4.0
CATEGORIES=	math python
MASTER_SITES=	PYPI/source/p/pyclipper
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Cython wrapper for the C++ translation of Clipper library
WWW=		https://github.com/fonttools/pyclipper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=1.11.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyclipper/_pyclipper${PYTHON_TAG}.so

.include <bsd.port.mk>
