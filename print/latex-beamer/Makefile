# New ports collection makefile for:	latex-beamer
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-beamer
PORTVERSION=	3.01
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX class to create a beamer presentation

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/${TEXMFLOCAL}/tex/latex/xcolor/xcolor.sty:${PORTSDIR}/print/latex-xcolor \
		${LOCALBASE}/${TEXMFLOCAL}/tex/latex/pgf/pgf.sty:${PORTSDIR}/print/latex-pgf \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

NO_BUILD=	YES
PLIST=		${WRKDIR}/pkg-plist

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_SUBDIRS=	base emulation emacs examples extensions lyx themes
DOC_SUBDIRS=	AUTHORS ChangeLog FILES INSTALL README TODO \
		doc solutions

IGNORE=		is already included in the teTeX distribution

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
	${ECHO_CMD} "@unexec ${MKTEXLSR}" >> ${PLIST}
	${ECHO_CMD} "@exec ${MKTEXLSR}" >> ${PLIST}

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
	${MKTEXLSR}

.include <bsd.port.mk>
