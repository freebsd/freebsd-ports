PORTNAME=	y2l
PORTVERSION=	1.2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yacc-to-Latex pretty printer/converter

NO_BUILD=	yes

PLIST_FILES=	bin/y2l man/man1/y2l.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/y2l ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/y2l.man ${STAGEDIR}${MANPREFIX}/man/man1/y2l.1

.include <bsd.port.mk>
