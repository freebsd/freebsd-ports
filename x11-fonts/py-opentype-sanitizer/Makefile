# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	opentype-sanitizer
PORTVERSION=	8.2.1
CATEGORIES=	x11-fonts python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper for the OpenType Sanitizer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	ots-sanitize:x11-fonts/ots

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils pytest

LDFLAGS+=	-lpython${PYTHON_VER}${PYTHON_ABIVER}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/src/python/ots/__init__.py
	@${RM} -r ${WRKSRC}/src/c/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
