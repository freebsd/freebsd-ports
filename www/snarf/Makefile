PORTNAME=	snarf
PORTVERSION=	7.0
CATEGORIES=	www
MASTER_SITES=	http://www.xach.com/snarf/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another small command-line URL (http/ftp/gopher/finger) fetcher
WWW=		https://www.xach.com/snarf/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/snarf \
		share/man/man1/snarf.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snarf ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/snarf.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
