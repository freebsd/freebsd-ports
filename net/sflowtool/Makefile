# New ports collection makefile for:  sflowtool
# Date created:        21 Mar 2006
# Whom:                Gregory Edigarov <greg@velcom.com>
#
# $FreeBSD$
#

PORTNAME=	sflowtool
PORTVERSION=	3.9
CATEGORIES=	net
MASTER_SITES=	http://www.inmon.com/bin/

MAINTAINER=	greg@velcom.com
COMMENT=	This is a sFlow capture and sFlow-to-NetFlow conversion tool

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/sflowtool
PORTDOCS=	README

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
