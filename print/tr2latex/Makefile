# New ports collection makefile for:	tr2latex
# Version required:     2.2
# Date created:         25 Jan 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $Id: Makefile,v 1.8 1998/01/06 08:53:12 tg Exp $
#

DISTNAME=	tr2latex
PKGNAME=	tr2latex-2.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support

MAINTAINER=	tg@FreeBSD.org

MAN1=		tr2latex.1

post-extract:
	${CP} ${WRKSRC}/Makefile.unix ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${PREFIX}/share/texmf/tex/latex/misc

.include <bsd.port.mk>
