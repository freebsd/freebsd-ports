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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A complete parser for RFC822 addresses

DOCS=		readme.html readme.txt user-manual.html user-manual.pdf

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile with gcc 3.4.2"
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/rfc822.hh ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/librfc822.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/documentation && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
