# New ports collection makefile for:	micq
# Date created:				11 Oct 1998
# Whom:					mph
#
# $FreeBSD$
#

PORTNAME=	micq
PORTVERSION=	0.4.8.pl3
PORTREVISION=
CATEGORIES=	net
MASTER_SITES=   ftp://micq.ukeer.de/pub/micq/source/
EXTRACT_SUFX=	.tgz
HAS_CONFIGURE=	yes

MAINTAINER=	ports@freebsd.org

MAN1=		micq.1
MAN5=		micqrc.5
MAN7=		micq.7

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/micq.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/micqrc.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/micq.7 ${MANPREFIX}/man/man7
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/micq
	${INSTALL_DATA} ${WRKSRC}/doc/commands.txt ${PREFIX}/share/doc/micq
	${INSTALL_DATA} ${WRKSRC}/doc/icq091.txt ${PREFIX}/share/doc/micq
	${INSTALL_DATA} ${WRKSRC}/doc/icqv7.txt ${PREFIX}/share/doc/micq
.endif

.include <bsd.port.mk>
