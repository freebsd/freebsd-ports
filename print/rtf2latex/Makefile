# New ports collection makefile for:	rtf2LaTeX
# Date created:		25 Jan 1995
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rtf2latex
PORTVERSION=	1.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/rtf2latex
DISTNAME=	rtf2LaTeX.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A filter that converts RTF (MS Rich Text Format) into LaTeX

WRKSRC=		${WRKDIR}/rtf2LaTeX

MAN1=		rtf2LaTeX.1

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
