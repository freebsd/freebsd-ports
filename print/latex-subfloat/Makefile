# New ports collection makefile for:	latex-subfloat
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-subfloat
PORTVERSION=	2.14.20030821
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/subfloat
DISTFILES=	Makefile subfloat.dtx subfloat.ins ${DOC_FILES}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package that enables subnumbering of different floats

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX
BUILD_DEPENDS+=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} MKTEXLSR=${MKTEXLSR}
PLIST_SUB+=	CLASSDIR=${CLASSDIR}

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEX_BIN=	${LOCALBASE}/bin/tex
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_FILES=	subfloat.dtx
CLASS_FILES+=	subfloat.sty
CLASS_FILES+=	subfloat.ins

DOC_FILES=	README
DOC_FILES+=	ChangeLog
DOC_FILES+=	subfloat.dvi
DOC_FILES+=	subfloat.xml

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${TEX_BIN} subfloat.ins

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	@${MKTEXLSR}

.include <bsd.port.mk>
