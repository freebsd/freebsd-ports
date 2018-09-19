# $FreeBSD$

PORTNAME=	pygslodeiv2
DISTVERSION=	0.9.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for odeiv2 in GNU Scientific Library (GSL)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libgsl.so:math/gsl
RUN_DEPENDS=	${PYNUMPY}

USES=		localbase python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
