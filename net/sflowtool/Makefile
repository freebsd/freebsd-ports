# New ports collection makefile for:  sflowtool
# Date created:        21 Mar 2006
# Whom:                Gregory Edigarov <greg@bestnet.kharkov.ua>
#
# $FreeBSD$
#

PORTNAME=	sflowtool
PORTVERSION=	3.13
CATEGORIES=	net
MASTER_SITES=	http://www.inmon.com/bin/

MAINTAINER=	greg@bestnet.kharkov.ua
COMMENT=	This is a sFlow capture and sFlow-to-NetFlow conversion tool

GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/sflowtool
PORTDOCS=	README

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
