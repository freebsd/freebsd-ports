# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	libsass
DISTVERSION=	0.14.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Straightforward binding of libsass for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to compile: cc1plus: error: unrecognized command line option -std=c++0x

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR}
LIB_DEPENDS=	libsass.so:textproc/libsass

USES=		localbase python
USE_PYTHON=	autoplist distutils

MAKE_ENV=	SYSTEM_SASS=1

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_sass.so

.include <bsd.port.mk>
