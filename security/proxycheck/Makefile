# New ports collection makefile for:	proxycheck
# Date created:				Fri Jun 13 02:26:04 EDT 2003
# Whom:					Paul Chvostek <paul@it.ca>
#
# $FreeBSD$
#

PORTNAME=	proxycheck
PORTVERSION=	0.45
CATEGORIES=	security

MAINTAINER=	paul+ports@it.ca
COMMENT=	Check for open proxy servers

MASTER_SITES=	http://www.corpit.ru/mjt/proxycheck/ \
		http://www.it.ca/~paul/src/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
MASTER_SITES+=	http://www.corpit.ru/mjt/ \
		http://www.it.ca/~paul/src/
DISTFILES+=	proxycheck.html
.endif

MAN1=		proxycheck.1

do-install:
		@${INSTALL_PROGRAM} ${WRKSRC}/proxycheck ${PREFIX}/sbin/
		@${INSTALL_MAN} ${WRKSRC}/proxycheck.1 ${PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
		@${INSTALL_DATA} ${DISTDIR}/proxycheck.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
