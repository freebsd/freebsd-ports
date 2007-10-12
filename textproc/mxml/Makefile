# New ports collection makefile for:	mxml
# Date created:		2007-10-12
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mxml
PORTVERSION=	2.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_EASYSW}
MASTER_SITE_SUBDIR=	mxml/2.3

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Small XML parsing library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack

MAN1=	mxmldoc.1
MAN3=	mxml.3

DOCS=	*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${DOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
