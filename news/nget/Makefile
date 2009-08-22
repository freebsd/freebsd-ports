# New ports collection makefile for:	nget
# Date created:				20 June 2002
# Whom:					George Sorsby <george@crackpipe.net>
#
# $FreeBSD$
#

PORTNAME=	nget
PORTVERSION=	0.27.1
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	SF
DISTNAME=	nget-${PORTVERSION}+uulib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Auto-resuming command line nntp file grabber

MAN1=		nget.1 ngetlite.1
MANCOMPRESSED=	no
USE_AUTOTOOLS=	autoconf:262
USE_GMAKE=	yes

post-extract:
	${LN} -s nget-${PORTVERSION} ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nget ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ngetlite ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nget.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/ngetlite.1 ${MANPREFIX}/man/man1

post-install:
	${STRIP_CMD} ${PREFIX}/bin/nget
	${STRIP_CMD} ${PREFIX}/bin/ngetlite
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README FAQ
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
