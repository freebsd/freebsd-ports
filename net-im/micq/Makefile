# New ports collection makefile for:	micq
# Version required:			26 June 1998
# Date created:				27 June 1998
# Whom:					mph
#
# $Id$
#

DISTNAME=	micq
PKGNAME=	micq-19980626
CATEGORIES=	net
MASTER_SITES=	ftp://micq.ml.org/pub/micq/Jun-26-98/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mph@freebsd.org

WRKSRC=		${WRKDIR}/micq-0626-98

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/micq ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/micq
.for file in README TODO WISHLIST commands.txt
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/micq
.endfor
.endif

.include <bsd.port.mk>
