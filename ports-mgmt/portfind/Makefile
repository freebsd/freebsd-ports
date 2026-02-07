PORTNAME=	portfind
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	ports-mgmt perl5
MASTER_SITES=	http://gug-it.de/files/

MAINTAINER=	thorsten@gug-it.de
COMMENT=	Search the ports tree
WWW=		http://www.gug-it.de

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	sqlite3:databases/sqlite3
RUN_DEPENDS=	sqlite3:databases/sqlite3

USES=		perl5
USE_PERL5=	build

PLIST_FILES=	bin/portfind share/man/man1/portfind.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/portfind ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/portfind.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
