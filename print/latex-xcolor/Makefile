# New ports collection makefile for:	latex-xcolor
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-xcolor
PORTVERSION=	2.00
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	latex-beamer
DISTNAME=	${PORTNAME:S/^latex-//}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package for driver-independent color extensions

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

NO_BUILD=	YES
PLIST_SUB=	MKTEXLSR=${MKTEXLSR} CLASSDIR=${CLASSDIR}

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_FILES=	xcolor.dtx xcolor.ins xcolor.sty

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
