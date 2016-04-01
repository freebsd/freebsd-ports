# Created by: David O'Brien <obrien@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lprps
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.jclark.com/pub/lprps/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	PostScript printer filter supporting a bidirectional serial channel

LIB_DEPENDS=	libpaper.so:print/libpaper

PORTDOCS=	INSTALL

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} textps psrev ${STAGEDIR}${PREFIX}/bin && \
		${INSTALL_PROGRAM} psif lprps psof ${STAGEDIR}${PREFIX}/libexec && \
		${INSTALL_SCRIPT} psif-text psif-ps ${STAGEDIR}${PREFIX}/libexec && \
		${INSTALL_DATA} banner.ps ${STAGEDIR}${DATADIR} && \
		${INSTALL_MAN} textps.n ${STAGEDIR}${PREFIX}/man/man1/textps.1 && \
		${INSTALL_MAN} psrev.n ${STAGEDIR}${PREFIX}/man/man1/psrev.1 && \
		${INSTALL_MAN} lprps.n ${STAGEDIR}${PREFIX}/man/man8/lprps.8 && \
		${INSTALL_MAN} psif.n ${STAGEDIR}${PREFIX}/man/man8/psif.8 && \
		${INSTALL_MAN} psof.n ${STAGEDIR}${PREFIX}/man/man8/psof.8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
