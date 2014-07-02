# $FreeBSD$

PORTNAME=	latex-beamer
PORTVERSION=	3.07
PORTREVISION=	5
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Version%20${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	LaTeX class to create a beamer presentation

OPTIONS_DEFINE=	DOCS

RUN_DEPENDS=	${LOCALBASE}/${TEXMFDIR}/tex/latex/pgf/basiclayer/pgf.sty:${PORTSDIR}/print/latex-pgf

USE_TEX=	latex
NO_BUILD=	YES

TEXMFDIR=	share/texmf
TEXMFDIR_LSR=	${LOCALBASE}/${TEXMFDIR}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME:S/^latex-//}

CLASS_SUBDIRS=	base emulation examples extensions themes
DOC_SUBDIRS=	AUTHORS ChangeLog FILES INSTALL README TODO \
		doc solutions
PORTDOCS=	*

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${CLASSDIR}
	cd ${WRKSRC} ; for d in ${CLASS_SUBDIRS}; do ${PAX} -rw $$d ${STAGEDIR}${PREFIX}/${CLASSDIR} ; done
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} ; for d in ${DOC_SUBDIRS}; do ${PAX} -rw $$d ${STAGEDIR}${DOCSDIR} ; done

.include <bsd.port.mk>
