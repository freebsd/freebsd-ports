PORTNAME=	pytidylib
PORTVERSION=	0.3.2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python wrapper for HTML Tidy (tidylib)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

OPTIONS_DEFAULT=TIDYHTML5
OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	TIDYLIB TIDYHTML5

BACKEND_DESC=	Backend library selection
TIDYLIB_DESC=	Use tidylib
TIDYHTML5_DESC=	Use tidy-html5

TIDYLIB_LIB_DEPENDS=	libtidy.so:www/tidy-lib
TIDYHTML5_LIB_DEPENDS=	libtidy5.so:www/tidy-html5

post-patch-TIDYHTML5-on:
	@${REINPLACE_CMD} -e '/LIB_NAMES/ s|\[.*\]|["libtidy5.so"]|' \
		${WRKSRC}/tidylib/tidy.py

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
