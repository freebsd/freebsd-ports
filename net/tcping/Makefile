# Created by: Dryice Liu
# $FreeBSD$

PORTNAME=	tcping
PORTVERSION=	1.3.6
CATEGORIES=	net

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Do a TCP connect to the given IP/port combination

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes

GH_ACCOUNT=	mkirchner

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
