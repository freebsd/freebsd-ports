PORTNAME=	pdftotext
PORTVERSION=	3.0.0
PORTREVISION=	4
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Simple PDF text extraction
WWW=		https://github.com/jalan/pdftotext

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpoppler-cpp.so:graphics/poppler

USES=		compiler:c11 python
USE_PYTHON=	autoplist distutils

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' \
	  -exec ${STRIP_CMD} {} +

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
