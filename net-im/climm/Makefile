# New ports collection makefile for:	micq
# Version required:                     0.4.4
# Date created:				11 Oct 1998
# Whom:					mph
#
# $FreeBSD$
#

DISTNAME=       micq-0.4.4
CATEGORIES=	net
MASTER_SITES=   ftp://micq.chatzone.org/pub/micq/V0.4.4/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@freebsd.org

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/micq
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/micq
.endif

.include <bsd.port.mk>
