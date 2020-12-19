# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iohexperimenter
PORTVERSION=	0.2.8.7
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IOHexperimenter-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Experimenter for Iterative Optimization Heuristic

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++14-lang dos2unix python:3.6+
USE_PYTHON=	autoplist concurrent distutils

USE_CXXSTD=	c++14

WRKSRC=		${WRKDIR}/IOHexperimenter-${PORTVERSION}

.include <bsd.port.mk>
