# Created by: Rainer Hurling <rhurlin@gwdg.de>

PORTNAME=	nlopt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.1
CATEGORIES=	math

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Nonlinear optimization library

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=	fails to package: Unable to access file site-packages/_nlopt.a:No such file or directory
BROKEN_armv7=	fails to package: Unable to access file site-packages/_nlopt.a:No such file or directory

BUILD_DEPENDS=	swig:devel/swig \
		${PYNUMPY}
LIB_DEPENDS=	libgmp.so:math/gmp \
		libguile-2.2.so:lang/guile2
RUN_DEPENDS=	${PYNUMPY}

USES=		cmake:testing compiler:features localbase pathfix pkgconfig python

USE_GITHUB=	yes
GH_ACCOUNT=	stevengj
USE_LDCONFIG=	yes

.include <bsd.port.mk>
