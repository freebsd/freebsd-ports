# New ports collection makefile for:	micq
# Date created:				11 Oct 1998
# Whom:					mph
#
# $FreeBSD$
#

PORTNAME=	micq
PORTVERSION=	0.4.5
CATEGORIES=	net
MASTER_SITES=   ftp://micq.chatzone.org/pub/micq/V0.4.5/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andrew@chg.ru

# There is something strange with distfile, so next line is really needed.
WRKSRC=		${WRKDIR}/micq-0.4.4

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/micq
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/micq
		${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${PREFIX}/share/doc/micq
.endif

.include <bsd.port.mk>
