# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-translate-cli
PORTVERSION=	0.0.1
#PORTREVISION=	0
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Google Translate to serve as a command line tool

BROKEN=		Checksum and size mismatch, strange LICENSE_PERMS for Beerware

LICENSE=	BW
LICENSE_NAME=	Beerware
LICENSE_TEXT=	http://www.sax.de/~joerg/beerware-license.txt
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

RUN_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

# same binary file bin/translate
CONFLICTS_INSTALL=	translate-*

GH_ACCOUNT=	soimort
GH_COMMIT=	2f59fc6
GH_TAGNAME=	${GH_COMMIT}
gawk_CMD=	${SETENV} -S gawk
gawk_OLD_CMD=	/usr/bin/gawk

MARKDOWN_CMD=	${LOCALBASE}/bin/markdown

OPTIONS_DEFINE=	DOCS

SHEBANG_FILES=	${WRKSRC}/translate.awk
SHEBANG_LANG=	gawk

USE_GITHUB=	yes
USES=	shebangfix

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,^gawk,${LOCALBASE}/bin/&,1' \
		-e 's,translate.awk,${DATADIR}/&,1' ${WRKSRC}/translate

.if !${PORT_OPTIONS:MDOCS}
NO_BUILD=	yes
.else
BUILD_DEPENDS+=	markdown:${PORTSDIR}/textproc/discount

do-build:
	@(cd ${WRKSRC} && \
	${MARKDOWN_CMD} README.md > README.tmp && \
	echo "<!DOCTYPE html><html><head><meta charset="UTF-8"><title>${COMMENT}</title></head><body>" | \
	${CAT} - ${WRKSRC}/README.tmp $(${ECHO_CMD} "</body></html>") > README.html)

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${STAGEDIR}${DOCSDIR}
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/translate ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/translate.awk ${STAGEDIR}${DATADIR}
	${LN} -sf ${DATADIR}/translate ${STAGEDIR}${PREFIX}/bin/translate
	${LN} -sf ${DATADIR}/translate ${STAGEDIR}${PREFIX}/bin/trs

regression-test test: build
	@(cd ${WRKSRC} ; ${MAKE} test)

.include <bsd.port.mk>
