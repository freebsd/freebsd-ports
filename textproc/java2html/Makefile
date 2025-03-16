PORTNAME=		java2html
PORTVERSION=		0.9.2
PORTREVISION=		2
CATEGORIES=		textproc www
MASTER_SITES=		SUNSITE/apps/www/converters

MAINTAINER=		mkamm@gmx.net
COMMENT=	Java sources to HTML converter
WWW=		http://user.cs.tu-berlin.de/~schintke/x2html/

LICENSE=	GPLv2

DEPRECATED=	Upstream is gone and last update 20 years ago
EXPIRATION_DATE=2025-04-30

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CONFLICTS_INSTALL=	source-highlight # bin/java2html

PORTDOCS=	AUTHORS NEWS README
PLIST_FILES=	bin/java2html share/man/man1/java2html.1.gz

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
