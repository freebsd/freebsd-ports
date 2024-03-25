PORTNAME=	pytidylib
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python wrapper for HTML Tidy (tidylib)
WWW=		http://countergram.com/open-source/pytidylib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

LIB_DEPENDS=	libtidy5.so:www/tidy-html5

post-patch:
	@${REINPLACE_CMD} -e '/LIB_NAMES/ s|\[.*\]|["libtidy5.so"]|' \
		${WRKSRC}/tidylib/tidy.py

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
