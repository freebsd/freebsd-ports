# Created by: vj562001@yahoo.de
# $FreeBSD$

PORTNAME=	biblatex
PORTVERSION=	0.9e
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/exptl
PKGNAMEPREFIX=	latex-
DISTNAME=	${PORTNAME}

MAINTAINER=	idolum@users.sourceforge.net
COMMENT=	Reimplementation of the LaTeX bibliographic facilities

RUN_DEPENDS=	${LOCALBASE}/${TEXMFLOCAL}/tex/latex/etoolbox/etoolbox.sty:${PORTSDIR}/print/latex-etoolbox

USES=		zip
USE_TEX=	latex
NO_BUILD=	YES
PLIST=		${WRKDIR}/pkg-plist

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEX_BIN=	${LOCALBASE}/bin/latex

CLASSNAME=	${PORTNAME}
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${CLASSNAME}
BSTDIR=		${TEXMFLOCAL}/bibtex/bst/biblatex
CSFDIR=		${TEXMFLOCAL}/bibtex/csf/biblatex
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

CLASS_FILES=	biblatex.cfg biblatex.def biblatex.sty blx-compat.def blx-natbib.def
DOC_FILES=	README RELEASE doc/biblatex.pdf doc/biblatex.tex
BST_FILES=	biblatex.bst

WRKSRC=		${WRKDIR}/${CLASSNAME}

OPTIONS_DEFINE=	BIBTEXT8_CSF DOCS
BIBTEXT8_CSF_DESC=	BibTeX8 sort definition files

NO_STAGE=	yes
.include <bsd.port.options.mk>

pre-install:
	(for F in ${CLASS_FILES}; do \
			${ECHO_CMD} "${CLASSDIR}/$${F}"; \
		done;) > ${PLIST}
	(for F in `${LS} -F ${WRKSRC}/latex | ${GREP} "/"`; do \
			for G in `${LS} ${WRKSRC}/latex/$${F}`; do \
				${ECHO_CMD} "${CLASSDIR}/$${F}$${G}"; \
			done; \
			${ECHO_CMD} "@dirrm ${CLASSDIR}/$${F}"; \
		done;) >> ${PLIST}
	${ECHO_CMD} "@dirrm ${CLASSDIR}" >> ${PLIST}
	(for F in ${BST_FILES}; do \
			${ECHO_CMD} "${BSTDIR}/$${F}"; \
		done;) >> ${PLIST}
	${ECHO_CMD} "@dirrm ${BSTDIR}" >> ${PLIST}
.if ${PORT_OPTIONS:MBIBTEXT8_CSF}
	(for F in `${LS} -F ${WRKSRC}/bibtex/csf`; do \
			${ECHO_CMD} "${CSFDIR}/$${F}"; \
		done;) >> ${PLIST}
	${ECHO_CMD} "@dirrm ${CSFDIR}" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MDOCS}
	(for F in ${DOC_FILES:S,^doc/,,}; do \
		${ECHO_CMD} "${DOCSDIR:S,^${PREFIX}/,,}/$${F}"; \
		done;) >> ${PLIST}
	${ECHO_CMD} "@dirrm ${DOCSDIR:S,^${PREFIX}/,,}" >> ${PLIST}
	(for F in `${LS} ${WRKSRC}/doc/examples`; do \
			${ECHO_CMD} "${EXAMPLESDIR:S,^${PREFIX}/,,}/$${F}"; \
		done;) >> ${PLIST}
	${ECHO_CMD} "@dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,}"  >> ${PLIST}
.endif
	${ECHO_CMD} "@exec ${MKTEXLSR}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${MKTEXLSR}" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	(cd ${WRKSRC}/latex/ && ${COPYTREE_SHARE} \* ${PREFIX}/${CLASSDIR})
	${MKDIR} ${PREFIX}/${BSTDIR}
	${INSTALL_DATA} ${BST_FILES:S@^@${WRKSRC}/bibtex/bst/@} ${PREFIX}/${BSTDIR}
.if ${PORT_OPTIONS:MBIBTEXT8_CSF}
	${MKDIR} ${PREFIX}/${CSFDIR}
	(cd ${WRKSRC}/bibtex/csf && ${COPYTREE_SHARE} \* ${PREFIX}/${CSFDIR})
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
	(cd ${WRKSRC}/doc/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
