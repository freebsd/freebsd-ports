# New ports collection makefile for:	py-pymc
# Date created:		2008-12-10
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pymc
PORTVERSION=	2.0r1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-2.0rc1

MAINTAINER=	wenheping@gmail.com
COMMENT=	Markov Chain Monte Carlo Sampling Toolkit

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${BUILD_DEPENDS}
#LIB_DEPENDS=	lapack.4:${PORTSDIR}/math/lapack

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFO=	${DISTNAME}-${PYTHON_VERSION:S/thon//}.egg-info

.include <bsd.port.mk>
