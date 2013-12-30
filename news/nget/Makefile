# Created by: George Sorsby <george@crackpipe.net>
# $FreeBSD$

PORTNAME=	nget
PORTVERSION=	0.27.1
PORTREVISION=	2
CATEGORIES=	news
MASTER_SITES=	SF
DISTNAME=	nget-${PORTVERSION}+uulib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Auto-resuming command line nntp file grabber

USES=		gmake
USE_GCC=	any
GNU_CONFIGURE=	yes

post-extract:
	${LN} -s nget-${PORTVERSION} ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nget ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ngetlite ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nget.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/ngetlite.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README FAQ
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
