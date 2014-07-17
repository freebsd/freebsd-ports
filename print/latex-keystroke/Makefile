# Created by: hrs@FreeBSD.org
# $FreeBSD$

PORTNAME=	latex-keystroke
PORTVERSION=	1.0.20001109
PORTREVISION=	5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/keystroke
DISTFILES=	${DOC_FILES} ${CLASS_FILES}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	#empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	LaTeX package for the graphical representation of the keys

USE_TEX=	latex
NO_BUILD=	YES
PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} MKTEXLSR=${MKTEXLSR} \
		CLASSDIR=${CLASSDIR}

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}

DOC_FILES=	README

CLASS_FILES=	key-test.pdf key-test.tex keystroke.sty \
		keystroke_left.eps keystroke_left.pdf keystroke_middle.eps \
		keystroke_middle.pdf keystroke_right.eps keystroke_right.pdf

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${DISTDIR}/${DIST_SUBDIR}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${DISTDIR}/${DIST_SUBDIR}/@} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
