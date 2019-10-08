# Created by: Dryice Liu
# $FreeBSD$

PORTNAME=	tcping
PORTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Do a TCP connect to the given IP/port combination

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS

CFLAGS+=	-DHAVE_HSTRERROR

PLIST_FILES=	bin/tcping
PORTDOCS=	README

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/tcping ${WRKSRC}/tcping.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcping ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
