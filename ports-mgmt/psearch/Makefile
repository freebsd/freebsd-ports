# Created by: Benjamin Lutz
# $FreeBSD$

PORTNAME=	psearch
PORTVERSION=	2.1.0
CATEGORIES=	ports-mgmt

MAINTAINER=	mail@maxlor.com
COMMENT=	Utility for searching the FreeBSD Ports Collection

LICENSE=	BSD2CLAUSE

USES=		compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	maxlor

PLIST_FILES=	bin/psearch \
		man/man1/psearch.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/psearch ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/psearch.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
