# Created by: G. Adam Stanislav <adam@whizkidtech.net>
# $FreeBSD$

PORTNAME=	felis
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays one or more files as a single line of text

PLIST_FILES=	bin/felis man/man1/felis.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/felis ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/felis.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
