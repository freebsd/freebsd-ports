# New ports collection makefile for:	latex-timing
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-timing
PORTVERSION=	1.0.19940515
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/timing
DISTFILES=	${DOC_FILES} ${CLASS_FILES} ${MF_FILES} ${PK_FILES} ${TFM_FILES}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	#empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package for drawing timing diagrams

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX
BUILD_DEPENDS+=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

NO_BUILD=	YES
PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} MKTEXLSR=${MKTEXLSR}
PLIST_SUB+=	CLASSDIR=${CLASSDIR}
PLIST_SUB+=	MFDIR=${MFDIR} TFMDIR=${TFMDIR} PKDIR=${PKDIR}

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
MFDIR=		${TEXMFLOCAL}/fonts/source/public/${PORTNAME:S/^latex-//}
TFMDIR=		${TEXMFLOCAL}/fonts/tfm/${PORTNAME:S/^latex-//}
PKDIR=		${TEXMFLOCAL}/fonts/pk/${PORTNAME:S/^latex-//}

DOC_FILES=	read.me
DOC_FILES+=	timing.dvi
DOC_FILES+=	timing.tex
DOC_FILES+=	prozt1.tex
DOC_FILES+=	tim0594.upl

CLASS_FILES=	timing.sty

MF_FILES=	timing.mf
MF_FILES+=	timing1.mf
MF_FILES+=	timing1s.mf
MF_FILES+=	timing2.mf
MF_FILES+=	timing2s.mf

PK_FILES=	timing1.pk
PK_FILES+=	timing1s.pk
PK_FILES+=	timing2.pk
PK_FILES+=	timing2s.pk

TFM_FILES=	timing1.tfm
TFM_FILES+=	timing1s.tfm
TFM_FILES+=	timing2.tfm
TFM_FILES+=	timing2s.tfm

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${DISTDIR}/${DIST_SUBDIR}/@} ${PREFIX}/${CLASSDIR}
	${MKDIR} ${PREFIX}/${MFDIR}
	${INSTALL_DATA} ${MF_FILES:S@^@${DISTDIR}/${DIST_SUBDIR}/@} ${PREFIX}/${MFDIR}
	${MKDIR} ${PREFIX}/${TFMDIR}
	${INSTALL_DATA} ${TFM_FILES:S@^@${DISTDIR}/${DIST_SUBDIR}/@} ${PREFIX}/${TFMDIR}
	${MKDIR} ${PREFIX}/${PKDIR}
	${INSTALL_DATA} ${PK_FILES:S@^@${DISTDIR}/${DIST_SUBDIR}/@} ${PREFIX}/${PKDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${DISTDIR}/${DIST_SUBDIR}/@} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
