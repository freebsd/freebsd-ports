# New ports collection makefile for:	latex-feynmf
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-feynmf
PORTVERSION=	1.08.19961202
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/feynmf
DISTFILES=	${DOC_FILES} Makefile feynmf.pl \
		feynmf.dtx feynmf.ins feynmf209.ins \
		manpics.1 manpics.2  manpics.3  manpics.mp
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	#empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package for drawing of Feynman diagrams

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} MKTEXLSR=${MKTEXLSR} \
		CLASSDIR=${CLASSDIR} FONTDIR=${FONTDIR} MPDIR=${MPDIR}

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEX_BIN=	${LOCALBASE}/bin/etex
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
FONTDIR=	${TEXMFLOCAL}/fonts/source/public/${PORTNAME:S/^latex-//}
MPDIR=		${TEXMFLOCAL}/metapost/${PORTNAME:S/^latex-//}

DOC_FILES=	Announce COPYING Feynman.Diagrams README \
		Tutorial manual.ps.gz template.tex

CLASS_FILES=	feynmf.dtx feynmf.ins feynmf209.ins \
		feynmf.sty feynmp.sty

SCRIPT_FILES=	feynmf.pl

FONT_FILES=	feynmf.mf
MP_FILES=	feynmp.mp manpics.mp manpics.1 manpics.2 manpics.3

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${TEX_BIN} feynmf.ins

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
	${MKDIR} ${PREFIX}/${FONTDIR}
	${INSTALL_DATA} ${FONT_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${FONTDIR}
	${MKDIR} ${PREFIX}/${MPDIR}
	${INSTALL_DATA} ${MP_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${MPDIR}
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${SCRIPT_FILES:S@^@${WRKSRC}/@} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
