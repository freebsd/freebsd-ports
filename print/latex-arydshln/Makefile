# Created by: hrs@FreeBSD.org
# $FreeBSD$

PORTNAME=	latex-arydshln
PORTVERSION=	1.71.20040831
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ctan.org/tex-archive/%SUBDIR%/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/arydshln
DISTFILES=	README arydshln-man.pdf arydshln.dtx arydshln.ins arydshln.pdf
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	LaTeX package that draws dash-lines in array/tabular

OPTIONS_DEFINE=	DOCS

USE_TEX=	latex

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEX_BIN=	${LOCALBASE}/bin/etex
YES_CMD=	/usr/bin/yes
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
CLASS_FILES=	arydshln.dtx arydshln.ins arydshln.sty arydshln-man.tex
PORTDOCS=	README arydshln-man.pdf
PLIST_FILES=	${CLASS_FILES:S@^@${CLASSDIR}/@} \
		"@exec ${MKTEXLSR}" \
		"@unexec ${MKTEXLSR}"
PLIST_DIRS=	${CLASSDIR}

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${YES_CMD} | ${TEX_BIN} arydshln.ins

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${STAGEDIR}${PREFIX}/${CLASSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
