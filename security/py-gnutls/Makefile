PORTNAME=	gnutls
PORTVERSION=	3.1.3
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-gnutls-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python wrapper for the GNUTLS library

LICENSE=	LGPL20

LIB_DEPENDS=	libgnutls.so:security/gnutls

USES=		python:3.6+ shebangfix
USE_PYTHON=	autoplist distutils
PYDISTUTILS_PKGNAME=	python_gnutls
NO_ARCH=	yes
SHEBANG_FILES=	examples/*.py

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${REINPLACE_CMD} -e "s|include_dirs=.*|include_dirs=\['${LOCALBASE}/include'\],|" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s|library_dirs=.*|library_dirs=\['${LOCALBASE}/lib'\],|" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s|\.26||g" ${WRKSRC}/gnutls/library/functions.py

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}/${EXAMPLESDIR}

.include <bsd.port.mk>
