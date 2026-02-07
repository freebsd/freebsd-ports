PORTNAME=	c2html
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	textproc www
MASTER_SITES=	SUNSITE/apps/www/converters

MAINTAINER=	mkamm@gmx.net
COMMENT=	C-language sources to HTML converter
WWW=		http://user.cs.tu-berlin.de/~schintke/x2html/

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/c2html share/man/man1/c2html.1.gz
PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
