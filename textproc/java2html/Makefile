# Created by: Martin Kammerhofer
# $FreeBSD$

PORTNAME=		java2html
PORTVERSION=		0.9.2
PORTREVISION=		1
CATEGORIES=		textproc www
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/converters

MAINTAINER=		mkamm@gmx.net
COMMENT=	Java sources to HTML converter

LICENSE=	GPLv2

USE_AUTOTOOLS=	autoconf213

PORTDOCS=	AUTHORS NEWS README
PLIST_FILES=	bin/java2html man/man1/java2html.1.gz

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
