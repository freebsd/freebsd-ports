# ex:ts=8
# Ports collection makefile for:	librfc822
# Date created:			Apr 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	librfc822
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	mail devel
MASTER_SITES=	http://cryp.to/librfc822/

MAINTAINER=	ismail@EnderUNIX.org
COMMENT=	A complete parser for RFC822 addresses

USE_GCC=	2.95
USE_REINPLACE=	yes

PORTDOCS=	readme.html readme.txt user-manual.html user-manual.pdf
PLIST_FILES=	include/rfc822.hh lib/librfc822.a

post-patch:
	@${REINPLACE_CMD} -E -e 's/^(CXX.*)=(.*)/\1\?=\2/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/rfc822.hh ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/librfc822.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/documentation && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
