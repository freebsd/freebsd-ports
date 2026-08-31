PORTNAME=	pygsl
PORTVERSION=	2.6.5
CATEGORIES=	math python
MASTER_SITES=	PYPI \
		https://github.com/pygsl/pygsl/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/pygsl/pygsl/commit/
PATCHFILES=	52d5f5dc8494f0cd1259dfd897dc1128a0de464d.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to GNU Scientific Library
WWW=		https://github.com/pygsl/pygsl

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meson-python>=0:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		swig:devel/swig
LIB_DEPENDS=	libgsl.so:math/gsl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		pkgconfig python
USE_PYTHON=	autoplist concurrent pep517

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
