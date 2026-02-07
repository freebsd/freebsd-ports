PORTNAME=	y2l
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yacc-to-Latex pretty printer/converter
WWW=		http://www.alchar.org/~aedil/Projects/y2l.html

NO_BUILD=	yes

PLIST_FILES=	bin/y2l share/man/man1/y2l.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/y2l ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/y2l.man ${STAGEDIR}${PREFIX}/share/man/man1/y2l.1

.include <bsd.port.mk>
