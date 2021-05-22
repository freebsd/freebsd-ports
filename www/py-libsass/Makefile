# Created by: Yuri Victorovich <yuri@rawbw.com>

PORTNAME=	libsass
DISTVERSION=	0.21.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Straightforward binding of libsass for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsass.so:textproc/libsass
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		compiler:c++11-lang localbase python:3.6+
USE_PYTHON=	autoplist distutils

MAKE_ENV=	SYSTEM_SASS=1

.include <bsd.port.mk>
