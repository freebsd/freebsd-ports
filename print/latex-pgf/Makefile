# New ports collection makefile for:	latex-pgf
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-pgf
PORTVERSION=	2.00
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pgf
DISTNAME=	${PORTNAME:S/^latex-//}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package for TeX Portable Graphic Format

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

NO_BUILD=	YES
PLIST_SUB=	MKTEXLSR=${MKTEXLSR} \
		CLASSDIR=${CLASSDIR} \
		TEXMFDIR=${TEXMFDIR}
PORTDOCS=	AUTHORS ChangeLog FILES INSTALL README TODO \
		pgfmanual.pdf \
		version-for-vtex version-for-tex4ht version-for-pdftex	\
		version-for-dvips version-for-dvipdfm text-en macros	\
		licenses images

TEXMFDIR=	share/texmf
TEXMFDIR_LSR=	${LOCALBASE}/${TEXMFDIR}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}-${PORTVERSION}
CLASSDIR=	${TEXMFDIR}/tex

do-install:
.for C in context generic latex plain
	${MKDIR} ${PREFIX}/${CLASSDIR}/${C}/${PORTNAME:S/^latex-//}
	${CP} -R ${WRKSRC}/${C}/pgf/* \
		${PREFIX}/${CLASSDIR}/${C}/${PORTNAME:S/^latex-//}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${CLASSDIR}/${C}/${PORTNAME:S/^latex-//}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/generic/pgf/* ${DOCSDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>
