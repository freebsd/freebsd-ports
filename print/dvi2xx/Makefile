# New ports collection makefile for:    dvi2xx
# Version required:     0.51alpha9
# Date created:         14 October 1994
# Whom:                 jmz
#
# $FreeBSD$
#

DISTNAME=	dvi2xx
PKGNAME=	dvi2xx-0.51a9
DISTFILES=	dvi2xx.tar.gz
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	dviware

MAINTAINER=	jmz@FreeBSD.org

MAN1=		dvi2xx.1
IGNOREFILES=	${DISTFILES}

pre-install:
	@${MKDIR} ${PREFIX}/lib/dvi2xx
	@(cd ${WRKSRC}; install -m 755 -c MakeTeXPK ${PREFIX}/bin)
	@(cd ${WRKSRC}; install -c -m 644 2up.sty  graybox.sty lj3-filter \
	  printcap.sample sample2.tex testpage.tex ${PREFIX}/lib/dvi2xx/)

.include <bsd.port.mk>
