PORTNAME=	pcalc
DISTVERSIONPREFIX=	v
DISTVERSION=	5
CATEGORIES=	math

MAINTAINER=	me@pacopascal.com
COMMENT=	Command line util for doing hex/dec/oct/bin math quickly
WWW=		https://vapier.github.io/pcalc/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison gmake
USE_GITHUB=	yes
GH_ACCOUNT=	vapier

PORTDOCS=	EXAMPLE README.md SYNTAX.md
OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/pcalc

TEST_TARGET=	check

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pcalc

.include <bsd.port.mk>
