# New ports collection makefile for:	py-urlgrabber
# Date created:		2007-09-22
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	urlgrabber
PORTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://linux.duke.edu/projects/urlgrabber/download/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A high-level cross-protocol url-grabber

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
