PORTNAME=	psearch
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	ports-mgmt

MAINTAINER=	mail@maxlor.com
COMMENT=	Utility for searching the FreeBSD Ports Collection
WWW=		https://github.com/maxlor/psearch

LICENSE=	BSD2CLAUSE

USES=		compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	maxlor

PLIST_FILES=	bin/psearch \
		share/man/man1/psearch.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/psearch ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/psearch.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
