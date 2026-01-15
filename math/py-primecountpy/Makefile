PORTNAME=	primecountpy
PORTVERSION=	0.2.1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Primecount Cython interface
WWW=		https://pypi.org/project/primecountpy/

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYDEPS}
LIB_DEPENDS=	libprimecount.so:math/primecount
RUN_DEPENDS=	${PYDEPS}

USES=		localbase meson pkgconfig python
USE_PYTHON=	cython
.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

PYDEPS=	${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}

post-build:
	${FIND} ${WRKSRC} -name "*gnu.so" -delete -o -name "*313.pyc" -delete

post-stage:
	${FIND} ${STAGEDIR} -name "*.cpp" -delete -o -name "*.pyx" -delete

.include <bsd.port.mk>
