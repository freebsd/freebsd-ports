# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	babelfont
PORTVERSION=	2.0.2
CATEGORIES=	x11-fonts python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Abstract interface to font source files based on fontParts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defcon>=0:x11-fonts/py-defcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fontparts>=0:print/py-fontparts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}glyphsLib>=0:x11-fonts/py-glyphsLib@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
