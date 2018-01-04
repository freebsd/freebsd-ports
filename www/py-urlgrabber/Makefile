# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urlgrabber
PORTVERSION=	3.10.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://urlgrabber.baseurl.org/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	High-level cross-protocol url-grabber

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycurl>=7.19.0_1:ftp/py-pycurl@${FLAVOR}

DOCS_MAKE_ENV=	INSTALL_DOCS=yes
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

REINPLACE_ARGS=	-i.bak -e 's,%%DOCSDIR%%,${DOCSDIR},'

SHEBANG_FILES=	scripts/urlgrabber-ext-down

USES=		python:2.7 shebangfix
USE_PYTHON=	distutils

post-patch:
	@${REINPLACE_CMD} ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
