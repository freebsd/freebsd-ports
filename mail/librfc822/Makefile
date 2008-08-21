# ex:ts=8
# Ports collection makefile for:	librfc822
# Date created:			Apr 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	librfc822
PORTVERSION=	1.2
CATEGORIES=	mail devel
MASTER_SITES=	http://cryp.to/librfc2822/

MAINTAINER=	ismail@EnderUNIX.org
COMMENT=	A complete parser for RFC822 addresses

GNU_CONFIGURE=	YES

PORTDOCS=	user-manual.html
PLIST_FILES=	include/rfc822.hpp lib/librfc822.a

do-install:
	${INSTALL_DATA} ${WRKSRC}/rfc822.hpp ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/librfc822.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
