# New ports collection makefile for:	latex-xcolor
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-xcolor
PORTVERSION=	1.06
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	latex-beamer
DISTNAME=	${PORTNAME:S/^latex-//}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package for driver-independent color extensions

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

NO_BUILD=	YES
PLIST_SUB=	TEXMF=${TEXMF} MKTEXLSR=${MKTEXLSR}
PLIST_SUB+=	CLASSDIR=${CLASSDIR}

TEXMF=		share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMF}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_FILES=	xcolor.dtx
CLASS_FILES+=	xcolor.ins
CLASS_FILES+=	xcolor.sty

DOC_FILES=	README
DOC_FILES+=	xcolor.pdf

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
