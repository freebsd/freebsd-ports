# New ports collection makefile for:	tr2latex
# Version required:     2.2
# Date created:         25 Jan 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	tr2latex
PKGNAME=	tr2latex-2.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support

MAINTAINER=	ports@FreeBSD.org

IGNOREFILES=	${DISTNAME}${EXTRACT_SUFX}

MAN1=		tr2latex.1

post-extract:
	${CP} ${WRKSRC}/Makefile.unix ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${PREFIX}/share/texmf/tex/latex/misc

.include <bsd.port.mk>
