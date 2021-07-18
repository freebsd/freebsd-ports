# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	glyphtools
PORTVERSION=	0.7.3
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Routines for extracting information from fontTools glyphs

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babelfont>=0.2.0:x11-fonts/py-babelfont@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beziers>=0:graphics/py-beziers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}glyphsLib>=0:x11-fonts/py-glyphsLib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
