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

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp

USES=		zip
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-extract:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
