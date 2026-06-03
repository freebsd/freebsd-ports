PORTNAME=		bc
PORTVERSION=		7.1.0
CATEGORIES=		math lang
MASTER_SITES=		https://github.com/gavinhoward/bc/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=		gh-

MAINTAINER=		se@FreeBSD.org
COMMENT=		GNU compatible bc/dc calculator
WWW=			https://github.com/gavinhoward/bc

LICENSE=		BSD2CLAUSE MIT
LICENSE_COMB=		multi
LICENSE_FILE=		${WRKSRC}/LICENSE.md

USES=			compiler:c11 tar:xz

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS+=	--predefined-build-type=BSD --disable-problematic-tests

TEST_TARGET=		test

CONFLICTS_INSTALL=	gnubc

OPTIONS_DEFAULT=	LIBEDIT
OPTIONS_RADIO=		HISTORY
OPTIONS_RADIO_HISTORY=	LIBEDIT READLINE INTERNAL
INTERNAL_DESC=		Command line editing via private functions

INTERNAL_CONFIGURE_ON=	--enable-internal-history

LIBEDIT_USES=		libedit
LIBEDIT_CONFIGURE_ON=	--enable-editline

READLINE_USES=		readline
READLINE_CONFIGURE_ON=	--enable-readline

pre-build:
		${INSTALL_SCRIPT} ${WRKSRC}/gen/strgen.sh ${WRKSRC}/gen/strgen

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/bin/bc ${STAGEDIR}${PREFIX}/bin/
		${LN} ${STAGEDIR}${PREFIX}/bin/bc ${STAGEDIR}${PREFIX}/bin/dc
		${INSTALL_MAN} ${WRKSRC}/manuals/bc.1 ${STAGEDIR}${PREFIX}/share/man/man1
		${INSTALL_MAN} ${WRKSRC}/manuals/dc.1 ${STAGEDIR}${PREFIX}/share/man/man1
		${MKDIR} ${STAGEDIR}${PREFIX}/share/nls/C
		${WRKSRC}/scripts/locale_install.sh ${STAGEDIR}${PREFIX}/share/nls/%L/%N.cat ${PORTNAME}
		${MV} ${STAGEDIR}${PREFIX}/share/nls/en_US/bc.cat ${STAGEDIR}${PREFIX}/share/nls/C/
		${RMDIR} ${STAGEDIR}${PREFIX}/share/nls/en_US

.include <bsd.port.mk>
