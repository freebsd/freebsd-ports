PORTNAME=	PyMuPDF
PORTVERSION=	1.22.5
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python bindings for the PDF toolkit and renderer MuPDF
WWW=		https://github.com/pymupdf/PyMuPDF

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		swig:devel/swig

USES=		gmake python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
