PORTNAME=	binclock
DISTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.ngolde.de/download/

MAINTAINER=	dereckson@gmail.com
COMMENT=	CLI binary clock
WWW=		http://www.ngolde.de/binclock.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTDOCS=	README
PLIST_FILES=	bin/binclock etc/binclockrc share/man/man1/binclock.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/binclock ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/binclockrc ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/doc/binclock.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/binclock

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
