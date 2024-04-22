PORTNAME=	felis
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays one or more files as a single line of text
WWW=		http://www.whizkidtech.redprince.net/fports/

PLIST_FILES=	bin/felis share/man/man1/felis.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/felis ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/felis.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
