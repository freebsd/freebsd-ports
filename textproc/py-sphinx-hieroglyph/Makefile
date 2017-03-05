# Created by: Andreas Sommer <andreas.sommer87@googlemail.com>
# $FreeBSD$

PORTNAME=	sphinx-hieroglyph
PORTVERSION=	0.7.1
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	andreas.sommer87@googlemail.com
COMMENT=	Sphinx extension which builds HTML presentations

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.3:textproc/py-sphinx

USE_GITHUB=	yes
GH_ACCOUNT=	nyergler
GH_PROJECT=	hieroglyph

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
