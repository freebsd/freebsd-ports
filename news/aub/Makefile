# Created by: David O'Brien (obrien@cs.ucdavis.edu)
# $FreeBSD$

PORTNAME=	aub
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://yukidoke.org/~mako/projects/aub/download/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Assemble usenet binaries

USES=		shebangfix
NO_BUILD=	yes

MANPAGE=	aub.1.sgml aubconf.1.sgml
PORTDOCS=	COPYING README aubconf.example
PLIST_FILES=	bin/aub man/man1/aub.1.sgml.gz man/man1/aubconf.1.sgml.gz
SHEBANG_FILES=	aub

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/aub ${STAGEDIR}${PREFIX}/bin
.for manpage in ${MANPAGE}
	${INSTALL_MAN} ${WRKSRC}/${manpage} ${STAGEDIR}${MANPREFIX}/man/man1
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
