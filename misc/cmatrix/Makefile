# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	cmatrix
PORTVERSION=	1.2a
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Show a scrolling 'Matrix' like screen

LICENSE=	GPLv1+ # though COPYING is GPLv2

USES=		gmake ncurses
GNU_CONFIGURE=	yes

PORTDOCS=	ChangeLog README TODO
PLIST_FILES=	bin/cmatrix man/man1/cmatrix.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmatrix ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cmatrix.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
