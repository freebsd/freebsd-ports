# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=		c2html
PORTVERSION=		0.9.6
CATEGORIES=		textproc www
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/converters

MAINTAINER=		mkamm@gmx.net
COMMENT=	C-language sources to HTML converter

LICENSE=	GPLv2

USE_AUTOTOOLS=	autoconf213

PLIST_FILES=	bin/c2html man/man1/c2html.1.gz
PORTDOCS=	AUTHORS NEWS README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
