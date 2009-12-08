# New ports collection makefile for:	latex-msc
# Date created:		12 Jul 2004
# Whom:		sg-sendpr@waset.de
#
# $FreeBSD$

PORTNAME=	latex-msc
PORTVERSION=	1.14
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ctan.org/tex-archive/%SUBDIR%/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/msc
DISTFILES=	${CLASS_FILES} ${PORTDOCS}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX macro package for drawing Message Sequence Charts

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base

BROKEN=		checksum mismatch
DEPRECATED=	has been broken for 3 months
EXPIRATION_DATE=2010-01-08

NO_SIZE=	yes # Most mirrors don't provide size-data

NO_BUILD=	yes
PLIST_SUB=	MKTEXLSR="${MKTEXLSR}" CLASSDIR=${CLASSDIR}

TEXMFDIR=	share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr ${PREFIX}/${TEXMFDIR}
CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_FILES=	msc.sty
PLIST_FILES=	%%CLASSDIR%%/msc.sty
PLIST_DIRS=	%%CLASSDIR%%
PORTDOCS=	README manual.tex refman.tex biblio.bib maintenance.tex

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	@${MKTEXLSR}

.include <bsd.port.mk>
