PORTNAME=	pfbtopfa
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.whizkidtech.redprince.net/pfbtopfa/ \
		ftp://ftp.whizkidtech.redprince.net/fonts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert PFB files to the PFA format

PLIST_FILES=	bin/pfbtopfa man/man1/pfbtopfa.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfbtopfa ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pfbtopfa.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
