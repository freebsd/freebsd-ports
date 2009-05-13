# New ports collection makefile for:	py-gmpy
# Date created:				09 July 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gmpy
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python Extension that Wraps the GMP Library

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/gmpy.so

.include <bsd.port.mk>
