PORTNAME=	gmpy2
DISTVERSION=	2.1.2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GMP/MPIR, MPFR, and MPC interface to Python
WWW=		https://pypi.org/project/gmpy2/

LICENSE=	GPLv3

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr

USES=		localbase python
USE_PYTHON=	distutils autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gmpy2/gmpy2*.so

.include <bsd.port.mk>
