PORTNAME=	openTSNE
DISTVERSION=	0.6.0
CATEGORIES=	math python # statistics
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, parallel implementations of t-SNE

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libfftw3.so:math/fftw3
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.20:science/py-scikit-learn@${PY_FLAVOR}

USES=		compiler:c++14-lang localbase:ldflags python:3.6+
USE_PYTHON=	distutils autoplist

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
