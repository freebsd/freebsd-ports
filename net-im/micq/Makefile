# New ports collection makefile for:	micq
# Date created:				11 Oct 1998
# Whom:					mph
#
# $FreeBSD$
#

PORTNAME=	micq
PORTVERSION=	0.4.8.3
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	http://micq.org/source/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/3/pl3/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes

MAN1=		micq.1
MAN5=		micqrc.5
MAN7=		micq.7

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/micq.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/micqrc.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/micq.7 ${MANPREFIX}/man/man7
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/commands.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/icq091.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/icqv7.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
