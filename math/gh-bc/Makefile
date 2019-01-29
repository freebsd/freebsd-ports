# $FreeBSD$

PORTNAME=	bc
PORTVERSION=	1.1.0
CATEGORIES=	math
PKGNAMEPREFIX=	gh-

MAINTAINER=	se@FreeBSD.org
COMMENT=	GNU compatible bc/dc calculator

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USE_GITHUB=	yes
GH_ACCOUNT=	gavinhoward

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS=	-G

CONFLICTS_INSTALL=	gnubc-[0-9]*

PLIST_FILES=	bin/bc bin/dc man/man1/bc.1.gz man/man1/dc.1.gz

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/bin/bc ${STAGEDIR}${PREFIX}/bin/
		${LN} ${STAGEDIR}${PREFIX}/bin/bc ${STAGEDIR}${PREFIX}/bin/dc
		${INSTALL_MAN} ${WRKSRC}/manuals/bc.1 ${STAGEDIR}${MANPREFIX}/man/man1
		${INSTALL_MAN} ${WRKSRC}/manuals/dc.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-test:
		${MAKE} -C ${WRKSRC} test

.include <bsd.port.mk>
