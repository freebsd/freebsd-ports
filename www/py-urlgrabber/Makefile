# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urlgrabber
PORTVERSION=	3.9.1
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://urlgrabber.baseurl.org/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	High-level cross-protocol url-grabber

LICENSE=	LGPL21

BUILD_DEPENDS=	${PKGNAMEPREFIX}curl>=7.19.0_1:${PORTSDIR}/ftp/py-curl
RUN_DEPENDS=	${PKGNAMEPREFIX}curl>=7.19.0_1:${PORTSDIR}/ftp/py-curl

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

REINPLACE_ARGS=	-i.bak -e 's,%%DOCSDIR%%,${DOCSDIR},'
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
MAKE_ENV=	INSTALL_DOCS=yes
.endif

post-patch:
	${REINPLACE_CMD} ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
