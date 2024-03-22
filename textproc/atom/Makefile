PORTNAME=	atom
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.bayofrum.net/dist/atom/ \
		http://muuz.deadbbs.com/FreeBSD/atom/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Converts text files to html with special attributes
WWW=		https://www.bayofrum.net/dist/atom/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/atom share/man/man1/atom.1.gz
PORTDOCS=	README TODO testFile

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
