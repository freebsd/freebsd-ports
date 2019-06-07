# $FreeBSD$

PORTNAME=	bc
PORTVERSION=	2.0.2
PORTREVISION=	2
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
CFLAGS+=	--std=c99

CONFLICTS_INSTALL=	gnubc-[0-9]*

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/bin/bc ${STAGEDIR}${PREFIX}/bin/
		${LN} ${STAGEDIR}${PREFIX}/bin/bc ${STAGEDIR}${PREFIX}/bin/dc
		${INSTALL_MAN} ${WRKSRC}/manuals/bc.1 ${STAGEDIR}${MANPREFIX}/man/man1
		${INSTALL_MAN} ${WRKSRC}/manuals/dc.1 ${STAGEDIR}${MANPREFIX}/man/man1
		${MKDIR} ${STAGEDIR}${PREFIX}/share/nls/C
		${WRKSRC}/locale_install.sh ${STAGEDIR}${PREFIX}/share/nls/%L/%N.cat ${PORTNAME}
		${MV} ${STAGEDIR}${PREFIX}/share/nls/en_US/bc.cat ${STAGEDIR}${PREFIX}/share/nls/C/

do-test:
		${MAKE} -C ${WRKSRC} test

.include <bsd.port.mk>
