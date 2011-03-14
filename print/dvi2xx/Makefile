# New ports collection makefile for:    dvi2xx
# Date created:         14 October 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	dvi2xx
PORTVERSION=	0.51.a9
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	dviware
DISTNAME=	dvi2xx

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert dvi files to HP LaserJet or IBM 3812 format

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

MAN1=		dvi2xx.1
IGNOREFILES=	${DISTFILES}

pre-install:
	@${MKDIR} ${PREFIX}/lib/dvi2xx
	@(cd ${WRKSRC}; install -m 755 -c MakeTeXPK ${PREFIX}/bin)
	@(cd ${WRKSRC}; install -c -m 644 2up.sty  graybox.sty lj3-filter \
	  printcap.sample sample2.tex testpage.tex ${PREFIX}/lib/dvi2xx/)

.include <bsd.port.mk>
