PORTNAME=	perl2html
PORTVERSION=	0.9.2
PORTREVISION=	2
CATEGORIES=	textproc www
MASTER_SITES=	SUNSITE/apps/www/converters

MAINTAINER=	mkamm@gmx.net
COMMENT=	Perl sources to HTML converter
WWW=		http://user.cs.tu-berlin.de/~schintke/x2html/

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
