# New ports collection makefile for:	latex-layouts
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-layouts
PORTVERSION=	2.6.20031125
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/layouts
DISTFILES=	${DOC_FILES} layouts.dtx layouts.ins
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	#empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package for the display of layout elements

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX
BUILD_DEPENDS+=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
BUILD_DEPENDS+=	tex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} MKTEXLSR=${MKTEXLSR}
PLIST_SUB+=	CLASSDIR=${CLASSDIR}

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEX_BIN=	${LOCALBASE}/bin/tex
YES_CMD=	/usr/bin/yes
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_FILES=	layouts.dtx
CLASS_FILES+=	layouts.ins
CLASS_FILES+=	layouts.sty

DOC_FILES=	README
DOC_FILES+=	layman.pdf
DOC_FILES+=	layman.tex

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${YES_CMD} | ${TEX_BIN} layouts.ins

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
