# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urlgrabber
PORTVERSION=	3.9.1
PORTREVISION=	4
CATEGORIES=	www python
MASTER_SITES=	http://urlgrabber.baseurl.org/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	High-level cross-protocol url-grabber

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PKGNAMEPREFIX}pycurl>=7.19.0_1:ftp/py-pycurl
RUN_DEPENDS=	${PKGNAMEPREFIX}pycurl>=7.19.0_1:ftp/py-pycurl

USES=		python:2.7
USE_PYTHON=	distutils

REINPLACE_ARGS=	-i.bak -e 's,%%DOCSDIR%%,${DOCSDIR},'
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

DOCS_MAKE_ENV=	INSTALL_DOCS=yes

post-patch:
	@${REINPLACE_CMD} ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
