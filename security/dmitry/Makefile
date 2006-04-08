# New ports collection makefile for:	DMitry
# Date created:		5 Feb 2005
# Whom:			Vaida Bogdan
#
# $FreeBSD$
#

PORTNAME=	dmitry
PORTVERSION=	1.3a
CATEGORIES=	security
MASTER_SITES=	http://www.mor-pah.net/code/ \
		http://www.deepmagic.org.uk/
DISTNAME=	DMitry-${PORTVERSION}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Deepmagic Information Gathering Tool

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
PLIST_FILES=	bin/dmitry

MAN1=		dmitry.1

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
