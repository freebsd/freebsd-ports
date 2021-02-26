# $FreeBSD$

PORTNAME=	iminuit
DISTVERSION=	2.4.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Jupyter-friendly Python frontend for MINUIT2 in C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++14-lang python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
