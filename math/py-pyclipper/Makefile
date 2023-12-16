PORTNAME=	pyclipper
PORTVERSION=	1.3.0p5
CATEGORIES=	math python
MASTER_SITES=	PYPI/source/p/pyclipper
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/.post/}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Cython wrapper for the C++ translation of Clipper library
WWW=		https://github.com/greginvm/pyclipper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.11.1:devel/py-setuptools_scm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyclipper/_pyclipper${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
