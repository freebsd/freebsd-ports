# Created by: Dryice Liu
# $FreeBSD$

PORTNAME=	tcping
PORTVERSION=	1.3.5
CATEGORIES=	net
MASTER_SITES=	http://www.linuxco.de/tcping/ \
		http://dryice.name/computer/FreeBSD/distfiles/

MAINTAINER=	dryice@dryice.name
COMMENT=	Do a TCP connect to the given IP/port combination

PLIST_FILES=	bin/tcping
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -DHAVE_HSTRERROR -o tcping tcping.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcping ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
