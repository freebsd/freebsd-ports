# $FreeBSD$

PORTNAME=	PyQuante
DISTVERSION=	1.6.5
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}-${DISTVERSION:R}/${PORTNAME}-${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum chemistry in Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: Src/PyQuante/contracted_gto.c:2063:46: error: no member named 'd_type' in 'PyMethodDescrObject'

RUN_DEPENDS=	${PYNUMPY}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
