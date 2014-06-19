# Created by: Henrik Brix Andersen <henrik@brixandersen.dk>
# $FreeBSD$

PORTNAME=	svninfo
PORTVERSION=	0.7.4
PORTREVISION=	5
CATEGORIES=	print
MASTER_SITES=	http://www.brucker.ch/projects/svninfo/download/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brix
PKGNAMEPREFIX=	latex-

MAINTAINER=	brix@FreeBSD.org
COMMENT=	A LaTeX package for Subversion support

LICENSE=	LPPL10

USE_TEX=	latex
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
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && ${TEX_BIN} svninfo.dtx
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${STAGEDIR}/${PREFIX}/${CLASSDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${STAGEDIR}/${DOCSDIR}
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.post.mk>
