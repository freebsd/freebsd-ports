PORTNAME=	nlopt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.1
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Nonlinear optimization library
WWW=		https://nlopt.readthedocs.io/en/latest/

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=	fails to package: Unable to access file site-packages/_nlopt.a:No such file or directory
BROKEN_armv7=	fails to package: Unable to access file site-packages/_nlopt.a:No such file or directory

BUILD_DEPENDS=	swig:devel/swig \
		${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		cmake:testing compiler:features guile:2.2,alias,conflicts \
		localbase pathfix pkgconfig python

USE_GITHUB=	yes
GH_ACCOUNT=	stevengj
USE_LDCONFIG=	yes

.include <bsd.port.mk>
