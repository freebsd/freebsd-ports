# New ports collection makefile for:	micq
# Version required:			11 Oct 1998
# Date created:				11 Oct 1998
# Whom:					mph
#
# $Id: Makefile,v 1.1.1.1 1998/06/28 03:22:36 mph Exp $
#

DISTNAME=	micq
PKGNAME=	micq-981011
CATEGORIES=	net
MASTER_SITES=	ftp://micq.ml.org/pub/micq/Oct-11-98/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mph@freebsd.org

WRKSRC=		${WRKDIR}/micq981011

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/micq
.for file in README TODO WISHLIST commands.txt
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/micq
.endfor
.endif

.include <bsd.port.mk>
