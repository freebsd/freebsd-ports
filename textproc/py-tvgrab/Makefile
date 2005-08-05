# New ports collection makefile for:	PyTVGrab
# Date created:		Sun May  8 07:22:39 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	TVGrab
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	pytvgrab
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${MASTER_SITE_SUBDIR}-lib-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A xmltv python library to write grabbers of tv scheduling collections

EXTRACT_DEPENDS=	${PYTHON_SITELIBDIR}/dateutil/__init__.py:${PORTSDIR}/devel/py-dateutil:extract

USE_BZIP2=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PORTDOCS=	README

post-extract:
	@${CP} ${FILESDIR}/timezone.py ${WRKSRC}/lib/timezone.py

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}

.include <bsd.port.mk>
