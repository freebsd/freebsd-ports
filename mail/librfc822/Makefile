# ex:ts=8
# Ports collection makefile for:	librfc822
# Date created:			Apr 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	librfc822
PORTVERSION=	1.0
CATEGORIES=	mail
MASTER_SITES=	http://cryp.to/librfc822/

MAINTAINER=	ports@FreeBSD.org

do-install:
	${INSTALL_DATA} ${WRKSRC}/rfc822.hh ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/librfc822.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/documentation/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
