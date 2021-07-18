PORTNAME=	pyEDFlib
DISTVERSION=	0.1.22
CATEGORIES=	misc
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python library to read/write EDF+/BDF+ files based on EDFlib

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		fortran python:3.6+
USE_PYTHON=	distutils cython autoplist

USE_GCC=	yes # fails to build with clang: https://github.com/holgern/pyedflib/issues/104

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyedflib/_extensions/_pyedflib*.so

.include <bsd.port.mk>
