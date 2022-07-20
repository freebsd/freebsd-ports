PORTNAME=	aub
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://yukidoke.org/~mako/projects/aub/download/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Assemble usenet binaries

USES=		shebangfix
SHEBANG_FILES=	aub
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	COPYING README aubconf.example
PLIST_FILES=	bin/aub man/man1/aub.1.sgml.gz man/man1/aubconf.1.sgml.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/aub ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aub*.1.sgml ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
