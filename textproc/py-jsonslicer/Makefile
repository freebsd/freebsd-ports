PORTNAME=	jsonslicer
PORTVERSION=	0.1.8
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Stream JSON parser for Python
WWW=		https://pypi.org/project/jsonslicer/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libyajl.so:devel/yajl

USES=		compiler:c++11-lang pkgconfig python
USE_PYTHON=	autoplist distutils

# pydistutils problem, it uses CC for compiling C++ code
CC=		${CXX}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/jsonslicer*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
