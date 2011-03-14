# New ports collection makefile for:	tr2latex
# Date created:         25 Jan 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tr2latex
PORTVERSION=	2.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert a document from troff to LaTeX

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

IGNOREFILES=	${DISTNAME}${EXTRACT_SUFX}

MAKEFILE=	Makefile.unix
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	tr2latex
MAN1=		tr2latex.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tr2latex ${PREFIX}/bin/tr2latex
	${INSTALL_MAN} ${WRKSRC}/tr2latex.man ${MANPREFIX}/man/man1/tr2latex.1
	@${MKDIR} ${PREFIX}/share/texmf/tex/latex/misc
.for file in troffman.sty troffms.sty
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/texmf/tex/latex/misc
.endfor

.include <bsd.port.mk>
