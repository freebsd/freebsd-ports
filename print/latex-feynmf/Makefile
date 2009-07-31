# New ports collection makefile for:	latex-feynmf
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-feynmf
PORTVERSION=	1.08.19961202
PORTREVISION=	5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/feynmf
DISTFILES=	${PORTDOCS} Makefile feynmf.pl \
		feynmf.dtx feynmf.ins feynmf209.ins \
		manpics.1 manpics.2  manpics.3  manpics.mp
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	#empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package for drawing of Feynman diagrams

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

PLIST_SUB=	TEXMFDIR=${TEXMFDIR} MKTEXLSR=${MKTEXLSR} \
		CLASSDIR=${CLASSDIR} FONTDIR=${FONTDIR} MPDIR=${MPDIR}

TEXMFDIR=	share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEX_BIN=	${LOCALBASE}/bin/etex
CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME:S/^latex-//}
FONTDIR=	${TEXMFDIR}/fonts/source/public/${PORTNAME:S/^latex-//}
MPDIR=		${TEXMFDIR}/metapost/${PORTNAME:S/^latex-//}

PORTDOCS=	Announce COPYING Feynman.Diagrams README \
		Tutorial manual.ps template.tex

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
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>
