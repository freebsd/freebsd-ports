# New ports collection makefile for: pynn
# Date created:			12 May 2010
# Whom:				Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pynn
PORTVERSION=	0.7.2
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyNN-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simulator-independent language for building neuronal network models

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PyNN

.include <bsd.port.mk>
