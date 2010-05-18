# New ports collection makefile for: pyNN
# Date created:			12 May 2010
# Whom:				Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pyNN
PORTVERSION=	0.6.0
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyNN-${PORTVERSION}

MAINTAINER=	jupengfei@gmail.com
COMMENT=	A simulator-independent language for building neuronal network models

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PyNN

.include <bsd.port.mk>
