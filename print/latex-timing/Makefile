# New ports collection makefile for:	latex-timing
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-timing
PORTVERSION=	1.0.19940515
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/timing
DISTFILES=	${DOC_FILES} ${CLASS_FILES} ${MF_FILES} ${PK_FILES} ${TFM_FILES}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	#empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package for drawing timing diagrams

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

NO_BUILD=	YES
PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} MKTEXLSR=${MKTEXLSR} \
		CLASSDIR=${CLASSDIR} \
		MFDIR=${MFDIR} TFMDIR=${TFMDIR} PKDIR=${PKDIR}

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

DOC_FILES=	read.me timing.dvi timing.tex prozt1.tex tim0594.upl

CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
CLASS_FILES=	timing.sty

MFDIR=		${TEXMFLOCAL}/fonts/source/public/${PORTNAME:S/^latex-//}
MF_FILES=	timing.mf timing1.mf timing1s.mf timing2.mf timing2s.mf

PKDIR=		${TEXMFLOCAL}/fonts/pk/${PORTNAME:S/^latex-//}
PK_FILES=	timing1.pk timing1s.pk timing2.pk timing2s.pk

TFMDIR=		${TEXMFLOCAL}/fonts/tfm/${PORTNAME:S/^latex-//}
TFM_FILES=	timing1.tfm timing1s.tfm timing2.tfm timing2s.tfm

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
