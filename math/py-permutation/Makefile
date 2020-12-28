# $FreeBSD$

PORTNAME=	permutation
DISTVERSION=	0.3.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Permutations of finitely many positive integers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

pre-configure: # permutation is officially built with "build" (https://github.com/pypa/build), but this is easily circumvented with this simple setup.py
	@( \
		${ECHO} "from setuptools import setup" && \
		${ECHO} "setup()" \
	) > ${WRKSRC}/setup.py

.include <bsd.port.mk>
