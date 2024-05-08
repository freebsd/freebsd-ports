PORTNAME=	cypari2
PORTVERSION=	2.1.5
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python interface to the number theory library PARI/GP
WWW=		https://github.com/sagemath/cypari2

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}
LIB_DEPENDS=	libgmp.so:math/gmp	\
		libpari.so:math/pari
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}
TEST_DEPENDS=	py.test:devel/py-pytest@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}flaky>=3.8.1:devel/py-flaky@${PY_FLAVOR}

#USE_GITHUB=	yes
#GH_ACCOUNT=	sagemath

USES=		compiler:c11 python
USE_PYTHON=	cython distutils

.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

PLIST_SUB+=	VER=${DISTVERSION}

do-test: install
	(cd ${WRKSRC} && py.test)

.include <bsd.port.mk>
