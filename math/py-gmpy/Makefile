PORTNAME=	gmpy
PORTVERSION=	1.17
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Extension that Wraps the GMP Library
WWW=		http://code.google.com/p/gmpy/

DEPRECATED=	EOLd, use math/py-gmpy2 instead
EXPIRATION_DATE=2023-06-30

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		python:3.6+ zip
USE_PYTHON=	distutils autoplist

post-extract:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
