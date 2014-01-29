# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tnef2txt
PORTVERSION=	1.4
CATEGORIES=	textproc converters
MASTER_SITES=	http://www.fiction.net/blong/programs/tnef2txt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable application/ms-tnef parser

ALL_TARGET=	tnef2txt
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/tnef2txt
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tnef2txt ${STAGEDIR}${PREFIX}/bin

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
