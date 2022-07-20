PORTNAME=	urlgrabber
PORTVERSION=	4.0.0
PORTREVISION=	0
CATEGORIES=	www python
MASTER_SITES=	http://urlgrabber.baseurl.org/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	High-level cross-protocol url-grabber

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.14.0:devel/py-six@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.14.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycurl>=7.19.0_1:ftp/py-pycurl@${PY_FLAVOR}

USES=		python:3.6+ shebangfix

DOCS_MAKE_ENV=	INSTALL_DOCS=yes
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

SHEBANG_FILES=	scripts/urlgrabber-ext-down

USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e 's,%%DOCSDIR%%,${DOCSDIR},' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
