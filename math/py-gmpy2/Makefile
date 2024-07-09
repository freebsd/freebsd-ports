PORTNAME=	gmpy2
DISTVERSION=	2.2.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GMP/MPIR, MPFR, and MPC interface to Python
WWW=		https://gmpy2.readthedocs.io/en/latest/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr

USES=		localbase python
USE_PYTHON=	distutils autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gmpy2/gmpy2*.so

.include <bsd.port.mk>
