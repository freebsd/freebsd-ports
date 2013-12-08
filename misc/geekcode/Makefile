# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	geekcode
PORTVERSION=	1.7.3
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Geek Code Generator

LICENSE=	GPLv2

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/geekcode
PORTDOCS=	geekcode.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/geekcode ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/geekcode.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
