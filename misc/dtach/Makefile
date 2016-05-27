# Created by: Bjorn Lindstrom <bkhl@elektrubadur.se>
# $FreeBSD$

PORTNAME=	dtach
PORTVERSION=	0.9
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulates the detach feature of screen

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
ALL_TARGET=	dtach

PORTDOCS=	README
PLIST_FILES=	bin/dtach man/man1/dtach.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dtach ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dtach.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
