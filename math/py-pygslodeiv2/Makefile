PORTNAME=	pygslodeiv2
DISTVERSION=	0.9.8
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for odeiv2 in GNU Scientific Library (GSL)
WWW=		https://github.com/bjodah/pygslodeiv2

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expired lang/cython0
EXPIRATION_DATE=2026-09-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libgsl.so:math/gsl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		compiler:c++11-lang localbase python
USE_PYTHON=	autoplist cython0 distutils pytest

pre-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} build_ext --inplace

.include <bsd.port.mk>
