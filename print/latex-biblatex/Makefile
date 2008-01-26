# New ports collection makefile for:	latex-biblatex
# Date created:		19 Jan 2008
# Whom:			vj562001@yahoo.de
#
# $FreeBSD$
#

PORTNAME=	biblatex
PORTVERSION=	0.7
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/exptl
PKGNAMEPREFIX=	latex-
DISTNAME=	${PORTNAME}

MAINTAINER=	vj562001@yahoo.de
COMMENT=	A reimplementation of the LaTeX biliographic facilities

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFLOCAL}/tex/latex/etoolbox/etoolbox.sty:${PORTSDIR}/print/latex-etoolbox

USE_ZIP=	YES
NO_BUILD=	YES
PLIST=		${WRKDIR}/pkg-plist

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEX_BIN=	${LOCALBASE}/bin/latex

CLASSNAME=	${PORTNAME}
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${CLASSNAME}
BSTDIR=		${TEXMFLOCAL}/bibtex/bst
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

CLASS_FILES=	biblatex.cfg biblatex.def bibnatex.def biblatex.sty
DOC_FILES=	README RELEASE doc/biblatex.pdf
BST_FILES=	biblatex.bst

WRKSRC=		${WRKDIR}/${CLASSNAME}

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
.if !defined(NOPORTDOCS)
	(for F in ${DOC_FILES:S,^doc/,,}; do \
		${ECHO_CMD} "${DOCSDIR:S,^${PREFIX}/,,}/$${F}"; \
		done;) >> ${PLIST}
	(for F in `${LS} -F ${WRKSRC}/doc | ${GREP} "/"`; do \
			for G in `${LS} ${WRKSRC}/doc/$${F}`; do \
				${ECHO_CMD} "${DOCSDIR:S,^${PREFIX}/,,}/$${F}$${G}"; \
			done; \
			${ECHO_CMD} "@dirrm ${DOCSDIR:S,^${PREFIX}/,,}/$${F}"; \
		done;) >> ${PLIST}
	${ECHO_CMD} "@dirrm ${DOCSDIR:S,^${PREFIX}/,,}"  >> ${PLIST}
.endif
	${ECHO_CMD} "@exec ${MKTEXLSR}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${MKTEXLSR}" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	(cd ${WRKSRC}/latex/ && ${COPYTREE_SHARE} \* ${PREFIX}/${CLASSDIR})
	${INSTALL_DATA} ${BST_FILES:S@^@${WRKSRC}/bibtex/@} ${PREFIX}/${BSTDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
