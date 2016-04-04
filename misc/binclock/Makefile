# Created by: Dereckson <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	binclock
DISTVERSION=	1.5
CATEGORIES=	misc
MASTER_SITES=	http://www.ngolde.de/download/

MAINTAINER=	dereckson@gmail.com
COMMENT=	CLI binary clock

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTDOCS=	README
PLIST_FILES=	bin/binclock etc/binclockrc man/man1/binclock.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/binclock ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/binclockrc ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/doc/binclock.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/binclock

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
