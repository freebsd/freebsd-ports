# New ports collection makefile for:	proxycheck
# Date created:				Fri Jun 13 02:26:04 EDT 2003
# Whom:					Paul Chvostek <paul@it.ca>
#
# $FreeBSD$
#

PORTNAME=	proxycheck
PORTVERSION=	0.49a
CATEGORIES=	security
MASTER_SITES=	http://www.corpit.ru/mjt/proxycheck/ \
		http://www.it.ca/~paul/src/

MAINTAINER=	paul+ports@it.ca
COMMENT=	Check for open proxy servers

MAN1=		proxycheck.1

HAS_CONFIGURE=	yes

do-install:
		@${INSTALL_PROGRAM} ${WRKSRC}/proxycheck ${PREFIX}/sbin/
		@${INSTALL_MAN} ${WRKSRC}/proxycheck.1 ${PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
.endif

.include <bsd.port.mk>
