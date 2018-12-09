# Created by: Rainer Hurling <rhurlin@gwdg.de>
# $FreeBSD$

PORTNAME=	nlopt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
CATEGORIES=	math

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Nonlinear optimization library

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		fails to package: Unable to access file site-packages/_nlopt.a:No such file or directory
BROKEN_armv7=		fails to package: Unable to access file site-packages/_nlopt.a:No such file or directory

LIB_DEPENDS=	libgmp.so:math/gmp \
		libguile-2.0.so:lang/guile2
BUILD_DEPENDS=	swig3.0:devel/swig30 \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.15.1:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.15.1:math/py-numpy@${PY_FLAVOR}

USES=		cmake compiler:features pathfix pkgconfig python:2.7
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	stevengj

# Needed to find gmp.h
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
