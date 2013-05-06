# $FreeBSD$

PORTNAME=	latex-beamer
PORTVERSION=	3.07
PORTREVISION=	5
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Version%20${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX class to create a beamer presentation

RUN_DEPENDS=	${LOCALBASE}/${TEXMFDIR}/tex/latex/pgf/basiclayer/pgf.sty:${PORTSDIR}/print/latex-pgf

USE_TEX=	tetex
NO_BUILD=	YES
PLIST=		${WRKDIR}/pkg-plist

TEXMFDIR=	share/texmf
TEXMFDIR_LSR=	${LOCALBASE}/${TEXMFDIR}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME:S/^latex-//}

CLASS_SUBDIRS=	base emulation emacs examples extensions lyx themes
DOC_SUBDIRS=	AUTHORS ChangeLog FILES INSTALL README TODO \
		doc solutions

pre-install:
	${RM} -f ${PLIST}
	${TOUCH} ${PLIST}
	cd ${WRKSRC} && ( \
		${FIND} ${CLASS_SUBDIRS} -type f | \
		${SED} -e "s%^%${CLASSDIR:S,^${PREFIX}/,,}/%"; \
		${FIND} ${CLASS_SUBDIRS} -type d | \
		${SORT} -r | ${SED} -e "s,^,@dirrm ${CLASSDIR:S,^${PREFIX}/,,}/,"; \
	) >> ${PLIST}
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ( \
		${FIND} ${DOC_SUBDIRS} -type f | \
		${SED} -e "s%^%${DOCSDIR:S,^${PREFIX}/,,}/%"; \
		${FIND} ${DOC_SUBDIRS} -type d | \
		${SORT} -r | ${SED} -e "s%^%@dirrm ${DOCSDIR:S,^${PREFIX}/,,}/%"; \
		${ECHO_CMD} "@dirrm ${DOCSDIR:S,^${PREFIX}/,,}"; \
	) >> ${PLIST}
.endif
	${ECHO_CMD} "@unexec ${MKTEXLSR} ${PREFIX}/${TEXMFDIR}" >> ${PLIST}
	${ECHO_CMD} "@exec ${MKTEXLSR} ${PREFIX}/${TEXMFDIR}" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	( cd ${WRKSRC} && ${TAR} cf - ${CLASS_SUBDIRS} ) | \
		( cd ${PREFIX}/${CLASSDIR} && ${TAR} xf - )
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	( cd ${WRKSRC} && ${TAR} cf - ${DOC_SUBDIRS} ) | \
		( cd ${DOCSDIR} && ${TAR} xf - )
.endif

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>
