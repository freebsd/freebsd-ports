# New ports collection makefile for:	rtf2LaTeX
# Version required:     1.5
# Date created:         25 Jan 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $Id: Makefile,v 1.6 1997/08/26 07:12:18 tg Exp $
#

DISTNAME=	rtf2LaTeX.1.5
PKGNAME=	rtf2latex-1.5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dante.de/pub/tex/support/rtf2latex/

MAINTAINER=	ports@FreeBSD.ORG

WRKSRC=		${WRKDIR}/rtf2LaTeX
MAN1=		rtf2LaTeX.1

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
