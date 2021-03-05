# $FreeBSD$

PORTNAME=	bc
PORTVERSION=	3.3.3
CATEGORIES=	math lang
PKGNAMEPREFIX=	gh-

MAINTAINER=	se@FreeBSD.org
COMMENT=	GNU compatible bc/dc calculator

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		compiler
USE_GITHUB=	yes
GH_ACCOUNT=	gavinhoward

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS=	-G

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc && ${COMPILER_VERSION} <= 42
CFLAGS+=	--std=c99
.endif

CONFLICTS_INSTALL=	gnubc-[0-9]*

pre-build:
		${INSTALL_SCRIPT} ${WRKSRC}/gen/strgen.sh ${WRKSRC}/gen/strgen

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/bin/bc ${STAGEDIR}${PREFIX}/bin/
		${LN} ${STAGEDIR}${PREFIX}/bin/bc ${STAGEDIR}${PREFIX}/bin/dc
		${INSTALL_MAN} ${WRKSRC}/manuals/bc.1 ${STAGEDIR}${MANPREFIX}/share/man/man1
		${INSTALL_MAN} ${WRKSRC}/manuals/dc.1 ${STAGEDIR}${MANPREFIX}/share/man/man1
		${MKDIR} ${STAGEDIR}${PREFIX}/share/nls/C
		${WRKSRC}/locale_install.sh ${STAGEDIR}${PREFIX}/share/nls/%L/%N.cat ${PORTNAME}
		${MV} ${STAGEDIR}${PREFIX}/share/nls/en_US/bc.cat ${STAGEDIR}${PREFIX}/share/nls/C/
		${RMDIR} ${STAGEDIR}${PREFIX}/share/nls/en_US

do-test:
		${MAKE} -C ${WRKSRC} test

.include <bsd.port.post.mk>
