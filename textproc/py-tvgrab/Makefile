# New ports collection makefile for:	PyTVGrab
# Date created:		Sun May  8 07:22:39 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	TVGrab
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	textproc python
MASTER_SITES=	SF/py${PORTNAME:L}/lib/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytvgrab-lib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A xmltv python library to write grabbers of tv scheduling collections

EXTRACT_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.4:${PORTSDIR}/devel/py-dateutil:extract

USE_BZIP2=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pytvgrab_lib

PORTDOCS=	README

post-extract:
	@${CP} ${FILESDIR}/timezone.py ${WRKSRC}/lib/timezone.py

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
