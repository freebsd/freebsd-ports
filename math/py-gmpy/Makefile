# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	gmpy
PORTVERSION=	1.17
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Extension that Wraps the GMP Library

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

USES=		python zip
USE_PYTHON=	distutils autoplist

post-extract:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
