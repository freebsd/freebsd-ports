PORTNAME=	pygslodeiv2
DISTVERSION=	0.9.4
PORTREVISION=	4
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for odeiv2 in GNU Scientific Library (GSL)
WWW=		https://github.com/bjodah/pygslodeiv2

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libgsl.so:math/gsl
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++11-lang localbase python
USE_PYTHON=	distutils autoplist cython pytest

pre-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} build_ext --inplace

.include <bsd.port.mk>
