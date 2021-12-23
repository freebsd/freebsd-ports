# Created by: Yuri Victorovich <yuri@rawbw.com>

PORTNAME=	gmpy2
DISTVERSION=	2.1.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GMP/MPIR, MPFR, and MPC interface to Python

LICENSE=	GPLv3

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr

USES=		localbase python:3.6-3.9
USE_PYTHON=	distutils autoplist

CONFLICTS=	${PYTHON_PKGNAMEPREFIX}gmpy2-devel-2.1*

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gmpy2/gmpy2*.so

.include <bsd.port.mk>
