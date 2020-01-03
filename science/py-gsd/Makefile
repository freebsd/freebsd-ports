# $FreeBSD$

PORTNAME=	gsd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.0
CATEGORIES=	science python
MASTER_SITES=	http://glotzerlab.engin.umich.edu/Downloads/gsd/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GSD (General Simulation Data) file format for Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY}
BUILD_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils cython autoplist

.include <bsd.port.mk>
