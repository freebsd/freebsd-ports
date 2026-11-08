PORTNAME=	portfind
PORTVERSION=	1.6.4
CATEGORIES=	ports-mgmt
MASTER_SITES=	https://github.com/Thorsten-Geppert/portfind/releases/download/v1.6.4/

MAINTAINER=	thorsten@tgeppert.de
COMMENT=	Search the ports tree
WWW=		https://www.tgeppert.com/portfind-for-freebsd/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	sqlite3:databases/sqlite3
RUN_DEPENDS=	sqlite3:databases/sqlite3

USES=		perl5
USE_PERL5=	build

PLIST_FILES=	bin/portfind \
		share/man/man1/portfind.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/portfind ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/portfind.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
