# New ports collection makefile for:	nget
# Date created:				20 June 2002
# Whom:					George Sorsby <george@crackpipe.net>
#
# $FreeBSD$
#

PORTNAME=	nget
PORTVERSION=	0.21
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nget
DISTNAME=	nget-${PORTVERSION}+uulib

MAINTAINER=	george@crackpipe.net

MAN1=		nget.1 ngetlite.1
MANCOMPRESSED=	no
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-extract:
	${LN} -s nget-${PORTVERSION} ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nget ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ngetlite ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nget.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/ngetlite.1 ${PREFIX}/man/man1

post-install:
	strip ${PREFIX}/bin/nget
	strip ${PREFIX}/bin/ngetlite

.include <bsd.port.mk>
