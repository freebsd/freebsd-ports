# Created by: ijliao
# $FreeBSD$

PORTNAME=	ttyload
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.daveltd.com/src/util/ttyload/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Give a color-coded graph of load averages over time

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

ALL_TARGET=	default

USE_BZIP2=	yes
PLIST_FILES=	bin/ttyload man/man1/ttyload.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_MAN} ${WRKSRC}/ttyload.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
