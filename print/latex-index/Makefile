# New ports collection makefile for:	latex-index
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-index
PORTVERSION=	4.02.b.20040120
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/${PORTNAME:S/^latex-//}
DISTFILES=	${DOC_FILES} ${CLASS_FILES}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package that reimplements LaTeX indexing macros

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX
BUILD_DEPENDS+=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
BUILD_DEPENDS+=	tex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} MKTEXLSR=${MKTEXLSR}
PLIST_SUB+=	CLASSDIR=${CLASSDIR}

USE_GMAKE=	YES
TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEX_BIN=	${LOCALBASE}/bin/tex
YES_CMD=	/usr/bin/yes
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_FILES=	agsmtst.tex
CLASS_FILES+=	autind.sty
CLASS_FILES+=	autind.tex
CLASS_FILES+=	bibref.ist
CLASS_FILES+=	bibref.sty
CLASS_FILES+=	index.dtx
CLASS_FILES+=	index.ins
CLASS_FILES+=	plaintst.tex
CLASS_FILES+=	test.bib
CLASS_FILES+=	xagsm.bst
CLASS_FILES+=	xplain.bst

CLASS_ADD_FILES+=	index.sty
CLASS_ADD_FILES+=	sample.tex

DOC_FILES=	README
DOC_FILES+=	TODO
DOC_FILES+=	index.pdf

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${YES_CMD} | ${TEX_BIN} index.ins

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} \
		${CLASS_ADD_FILES:S@^@${WRKSRC}/@} \
		${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	@${MKTEXLSR}

.include <bsd.port.mk>
