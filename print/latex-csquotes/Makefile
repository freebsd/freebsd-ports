# New ports collection makefile for:	latex-csquotes
# Date created:		31 Aug 2008
# Whom:			vj562001@yahoo.de
#
# $FreeBSD$

PORTNAME=	csquotes
PORTVERSION=	4.4a
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib
PKGNAMEPREFIX=	latex-
DISTNAME=	${PORTNAME}

MAINTAINER=	vj562001@yahoo.de
COMMENT=	Context sensitive quotation facilities

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
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

CLASS_FILES=	csquotes.sty csquotes.def csquotes.cfg
DOC_FILES=	LICENSE README csquotes.pdf tutorial.tex

WRKSRC=		${WRKDIR}/${CLASSNAME}

pre-install:
	(for F in ${CLASS_FILES}; do \
			${ECHO_CMD} "${CLASSDIR}/$${F}"; \
		done;) > ${PLIST}
	${ECHO_CMD} "@dirrm ${CLASSDIR}" >> ${PLIST}
.if !defined(NOPORTDOCS)
	(for F in ${DOC_FILES}; do \
		${ECHO_CMD} "${DOCSDIR:S,^${PREFIX}/,,}/$${F}"; \
		done;\
	${ECHO_CMD} "@dirrm ${DOCSDIR:S,^${PREFIX}/,,}" ) >> ${PLIST}
.endif
	${ECHO_CMD} "@exec ${MKTEXLSR}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${MKTEXLSR}" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
