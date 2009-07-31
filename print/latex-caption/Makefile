# New ports collection makefile for:	latex-caption
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-caption
PORTVERSION=	3.1.20080401
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ctan.org/tex-archive/%SUBDIR%/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/caption
DISTFILES=	${SRC_FILES} ${PORTDOCS}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package that supports customization of captions

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMF_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${TEXMF_LSR}:${PORTSDIR}/print/tex-texmflocal

PLIST_SUB=	MKTEXLSR=${MKTEXLSR} \
		TEXMFDIR=${TEXMFDIR}

TEXMFDIR=	share/texmf
TEXMF_LSR=	${LOCALBASE}/${TEXMFDIR}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEX_BIN=	${LOCALBASE}/bin/etex
YES_CMD=	/usr/bin/yes
CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}
PLIST_FILES=	${SRC_FILES:S,^,${CLASSDIR}/,} \
		${CLASS_FILES:S,^,${CLASSDIR}/,}

SRC_FILES=	caption.dtx caption2.dtx caption.ins \
		ltcaption.dtx subcaption.dtx
CLASS_FILES=	caption.sty caption2.sty caption3.sty \
		ltcaption.sty subcaption.sty
PORTDOCS=	README caption.pdf caption2.pdf \
		ltcaption.pdf subcaption.pdf \
		caption-eng.pdf caption-deu.pdf caption-rus.pdf \
		caption-eng.tex caption-deu.tex caption-rus.tex \
		cat.eps elephant.eps

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${YES_CMD} | ${TEX_BIN} caption.ins

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${SRC_FILES:S@^@${WRKSRC}/@} \
		${CLASS_FILES:S@^@${WRKSRC}/@} \
		${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	@${MKTEXLSR} ${LOCALBASE}/${TEXMFDIR}

.include <bsd.port.mk>
