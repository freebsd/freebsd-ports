# Created by: Ju Pengfei <ju.pengfei@gmail.com>

PORTNAME=	numexpr
PORTVERSION=	2.7.3
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast numerical array expression evaluator for Python and NumPy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.7,1:math/py-numpy@${PY_FLAVOR}

USES=		dos2unix python:3.6+
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/numexpr/interpreter*.so

.include <bsd.port.mk>
