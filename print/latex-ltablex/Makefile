# New ports collection makefile for:	print/latex-ltablex
# Date created:		14 April 2011
# Whom:			Raphael Kubo da Costa (kubito@gmail.com)
#
# $FreeBSD$

PORTNAME=	ltablex
PORTVERSION=	1.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib
PKGNAMEPREFIX=	latex-
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	latex

MAINTAINER=	kubito@gmail.com
COMMENT=	Combines the features of both the tabularx and longtable packages

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

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

CLASS_FILES=	ltablex.sty
DOC_FILES=	ltablex.pdf ltablex.tex

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
