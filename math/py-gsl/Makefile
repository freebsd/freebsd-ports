# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	gsl
PORTVERSION=	2.1.1
CATEGORIES=	math python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/py${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygsl-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to GNU Scientific Library

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
