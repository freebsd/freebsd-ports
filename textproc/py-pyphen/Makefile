PORTNAME=	pyphen
PORTVERSION=	0.13.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Module to hyphenate text based on Hunspell dictionaries
WWW=		https://pyphen.org/

LICENSE=	GPLv2 LGPL21 MPL11
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING.GPL
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING.MPL

USES=		python:3.6+
USE_PYTHON=	autoplist distutils pytest

NO_ARCH=	yes

pre-configure:
	@( \
		${ECHO} "from setuptools import setup" && \
		${ECHO} "setup()" \
	) > ${WRKSRC}/setup.py

.include <bsd.port.mk>
