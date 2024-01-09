PORTNAME=	apparix
PORTVERSION=	20110303
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://micans.org/apparix/src/
DISTNAME=	${PORTNAME}-11-062

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bookmark directories and apparate inside them
WWW=		https://micans.org/apparix/

LICENSE=	GPLv2+ # though code says GPLv3 or later
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PORTDOCS=	apparix.azm apparix.html apparix.ps
PLIST_FILES=	bin/apparix share/man/man1/apparix.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/apparix ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/apparix.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
