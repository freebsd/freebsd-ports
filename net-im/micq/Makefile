# New ports collection makefile for:	micq
# Version required:			0.3.3
# Date created:				11 Oct 1998
# Whom:					mph
#
# $Id: Makefile,v 1.3 1998/12/14 22:36:07 mph Exp $
#

DISTNAME=	micq
PKGNAME=	micq-0.3.3
CATEGORIES=	net
MASTER_SITES=	ftp://micq.chatzone.org/pub/micq/V0.3.3/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mph@freebsd.org

WRKSRC=		${WRKDIR}/micq981218

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/micq
.for file in README TODO WISHLIST commands.txt
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/micq
.endfor
.endif

.include <bsd.port.mk>
