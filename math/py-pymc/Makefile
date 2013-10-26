# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pymc
PORTVERSION=	2.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Markov Chain Monte Carlo Sampling Toolkit

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
