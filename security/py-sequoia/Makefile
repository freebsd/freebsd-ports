# $FreeBSD$

PORTNAME=	sequoia
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.0
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	phryk-ports@wzff.de
COMMENT=	Python binding of sequoia

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../../../LICENSE.txt

LIB_DEPENDS=	libsequoia_ffi.so:security/sequoia
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1:devel/py-cffi@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	distutils autoplist concurrent
USE_GITLAB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${GL_COMMIT}-${GL_COMMIT}/ffi/lang/python

GL_ACCOUNT=	sequoia-pgp
GL_PROJECT=	sequoia
GL_COMMIT=	383133f6be990237044900a4df676488bf8dd71e
CFLAGS+=	-I${LOCALBASE}/include

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_sequoia.abi3.so

.include <bsd.port.mk>
