# New ports collection makefile for:	DMitry
# Date created:		5 Feb 2005
# Whom:			Vaida Bogdan
#
# $FreeBSD$
#

PORTNAME=	DMitry
PORTVERSION=	1.2a
CATEGORIES=	security
MASTER_SITES=	http://www.mor-pah.net/code/ \
		http://www.deepmagic.org.uk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Deepmagic Information Gathering Tool

HAS_CONFIGURE=	yes

MAN1=		dmitry.1
MANCOMPRESSED=	no

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
