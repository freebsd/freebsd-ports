# Created by: idolum@users.sourceforge.net
# $FreeBSD$

PORTNAME=	logreq
PORTVERSION=	1.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib
PKGNAMEPREFIX=	latex-
DISTNAME=	${PORTNAME}

MAINTAINER=	idolum@users.sourceforge.net
COMMENT=	Support for automation of the LaTeX workflow

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
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

CLASS_FILES=	logreq.def logreq.sty
DOC_FILES=	README

WRKSRC=		${WRKDIR}/${CLASSNAME}

NO_STAGE=	yes
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
	(for F in `${LS} ${WRKSRC}/examples`; do \
			${ECHO_CMD} "${EXAMPLESDIR:S,^${PREFIX}/,,}/$${F}"; \
		done;) >> ${PLIST}
	${ECHO_CMD} "@dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,}"  >> ${PLIST}
.endif
	${ECHO_CMD} "@exec ${MKTEXLSR}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${MKTEXLSR}" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
