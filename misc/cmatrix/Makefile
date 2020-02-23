# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	cmatrix
PORTVERSION=	2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	ed.arrakis@gmail.com
COMMENT=	Show a scrolling 'Matrix' like screen

LICENSE=	GPLv3+

USES=		autoreconf ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	abishekvashok

GNU_CONFIGURE=	yes

PORTDOCS=	README
PLIST_FILES=	bin/cmatrix \
		man/man1/cmatrix.1.gz

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
