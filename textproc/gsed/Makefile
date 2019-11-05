# Created by: Cyrille Lefevre <clefevre@citeweb.net>
# $FreeBSD$

PORTNAME=	sed
PORTVERSION=	4.7
CATEGORIES=	textproc
MASTER_SITES=	GNU
PKGNAMEPREFIX=	g

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU stream editor

LICENSE=	GPLv3+ GFDL
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING

USES=		charsetfix makeinfo tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
CONFIGURE_ENV+=	MAKEINFO="${MAKEINFO} --no-split"
TEST_TARGET=	check

DATADIR=	${PREFIX}/share/${PKGBASE}
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}
INFO=		sed
PORTDOCS=	AUTHORS BUGS ChangeLog ChangeLog-2014 NEWS README THANKS
PORTEXAMPLES=	binary*.sed dc.sed

OPTIONS_DEFINE=	NLS DOCS EXAMPLES
OPTIONS_SUB=	yes

NLS_USES=	gettext iconv
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} 's,^\* sed:,* GNU sed:,' \
		${WRKSRC}/doc/config.texi

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/testsuite/,} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
