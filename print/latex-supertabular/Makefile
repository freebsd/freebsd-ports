# New ports collection makefile for:	latex-supertabular
# Date created:				Aug 20 2008
# Whom:					Jorge Niedbalski <niedbalski@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	latex-supertabular
PORTVERSION=	1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://tug.ctan.org/pub/tex-archive/macros/latex/contrib/supertabular/
DISTFILES=	supertabular.dtx supertabular.ins ${DOC_FILES}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	niedbalski@gmail.com
COMMENT=	A LaTeX package for a tabular that spans multiple pages

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} MKTEXLSR=${MKTEXLSR} \
		CLASSDIR=${CLASSDIR}
USE_GMAKE=	yes
TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEX_BIN=	${LOCALBASE}/bin/latex
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}
CLASS_FILES=	supertabular.dtx supertabular.sty supertabular.ins
DOC_FILES=	README MANIFEST CATALOG supertabular.pdf

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${TEX_BIN} supertabular.ins

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	@${MKTEXLSR} ${TEXMFLOCAL}

.include <bsd.port.mk>
