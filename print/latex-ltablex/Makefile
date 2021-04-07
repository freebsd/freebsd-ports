PORTNAME=	ltablex
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	print
# As of 2012-08-24, some mirrors are returning a tarball with a
# different checksum, so I am mirroring it locally instead.
# MASTER_SITES=	TEX_CTAN/macros/latex/contrib
MASTER_SITES=	LOCAL/rakuco/latex
PKGNAMEPREFIX=	latex-
DIST_SUBDIR=	latex

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Combines the features of both the tabularx and longtable packages

USES=		zip
USE_TEX=	latex texhash
NO_BUILD=	yes
PLIST_SUB=	CLASSDIR=${CLASSDIR}

OPTIONS_DEFINE=	DOCS

TEXMFDIR=	share/texmf
CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME}
CLASS_FILES=	ltablex.sty
PORTDOCS=	ltablex.pdf ltablex.tex

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${STAGEDIR}${PREFIX}/${CLASSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
