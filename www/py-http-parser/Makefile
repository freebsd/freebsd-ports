PORTNAME=	http-parser
DISTVERSION=	0.9.0
CATEGORIES=	www
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	HTTP request/response parser for python in C
WWW=		https://github.com/benoitc/http-parser/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist cython distutils

post-configure:
	cython-${PYTHON_VER} ${WRKSRC}/http_parser/parser.pyx

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/http_parser/parser*.so

.include <bsd.port.mk>
