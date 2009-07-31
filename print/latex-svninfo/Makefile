# New ports collection makefile for:	latex-svninfo
# Date created:		05 Dec 2006
# Whom:			Henrik Brix Andersen <henrik@brixandersen.dk>
#
# $FreeBSD$

PORTNAME=	svninfo
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.brucker.ch/projects/svninfo/download/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brix
PKGNAMEPREFIX=	latex-

MAINTAINER=	brix@FreeBSD.org
COMMENT=	A LaTeX package for Subversion support

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

PLIST_SUB=	MKTEXLSR=${MKTEXLSR} CLASSDIR=${CLASSDIR}

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEX_BIN=	${LOCALBASE}/bin/latex
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME}

CLASS_FILES=	svninfo.sty svninfo.cfg
PORTDOCS=	README svninfo.dvi

.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC} && ${TEX_BIN} svninfo.ins
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${TEX_BIN} svninfo.dtx
.endif

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.post.mk>
