# New ports collection makefile for:	micq
# Version required:			13 Dec 1998
# Date created:				11 Oct 1998
# Whom:					mph
#
# $Id: Makefile,v 1.2 1998/10/26 17:58:29 mph Exp $
#

DISTNAME=	micq
PKGNAME=	micq-0.3.2
CATEGORIES=	net
MASTER_SITES=	ftp://micq.ml.org/pub/micq/V0.3.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mph@freebsd.org

WRKSRC=		${WRKDIR}/micq981213

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/micq
.for file in README TODO WISHLIST commands.txt
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/micq
.endfor
.endif

.include <bsd.port.mk>
