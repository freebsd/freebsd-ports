# New ports collection makefile for:	py-urlgrabber
# Date created:		2007-09-22
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	urlgrabber
PORTVERSION=	3.9.1
PORTREVISION=	0
CATEGORIES=	www python
MASTER_SITES=	http://urlgrabber.baseurl.org/download/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A high-level cross-protocol url-grabber

BUILD_DEPENDS=	${PKGNAMEPREFIX}curl>=7.19.0_1:${PORTSDIR}/ftp/py-curl
RUN_DEPENDS=	${PKGNAMEPREFIX}curl>=7.19.0_1:${PORTSDIR}/ftp/py-curl

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

REINPLACE_ARGS=	-i.bak -e 's,%%DOCSDIR%%,${DOCSDIR},'
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

.if defined(NOPORTDOCS)
MAKE_ENV=	NOPORTDOCS=${NOPORTDOCS}
.endif

post-patch:
	${REINPLACE_CMD} ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
