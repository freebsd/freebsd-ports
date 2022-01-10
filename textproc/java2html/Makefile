# Created by: Martin Kammerhofer

PORTNAME=		java2html
PORTVERSION=		0.9.2
PORTREVISION=		1
CATEGORIES=		textproc www
MASTER_SITES=		SUNSITE/apps/www/converters

MAINTAINER=		mkamm@gmx.net
COMMENT=	Java sources to HTML converter

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	source-highlight # bin/java2html

PORTDOCS=	AUTHORS NEWS README
PLIST_FILES=	bin/java2html man/man1/java2html.1.gz

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
