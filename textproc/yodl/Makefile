# New ports collection makefile for:    yodl
# Version required:     1.22
# Date created:         22 Oct 1997
# Whom:                 Donald Burr <dburr@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1998/07/20 23:55:33 dburr Exp $
#

DISTNAME=	yodl-1.22
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.icce.rug.nl/pub/unix/

MAINTAINER=	dburr@FreeBSD.ORG

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash1 \
		latex:${PORTSDIR}/print/latex \
		dvips:${PORTSDIR}/print/dvips
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash1 \
		latex:${PORTSDIR}/print/latex \
		dvips:${PORTSDIR}/print/dvips

USE_GMAKE=	YES

MAN1=		yodl.1 \
		striproff.1 \
		yodlconverters.1
MAN5=		yodl.5
MAN7=		yodlmacros.7 \
		yodlmanpage.7

do-build:
	(cd ${WRKSRC} && env CFLAGS="${CFLAGS}" ${GMAKE} PREFIX=${PREFIX} progs)
	(cd ${WRKSRC}/misc && gcc ${CFLAGS} -s -o striproff striproff.c)

# this weird contortion is because the YODL makefile is broken
# trust me, it works.
do-install:
	@echo "*** NOTE: any errors from make can be safely ignored."
	(cd ${WRKSRC} && ${GMAKE} PREFIX=${PREFIX} install)
	-(cd ${WRKSRC} && ${GMAKE} PREFIX=${PREFIX} manpages)
	(cd ${WRKSRC}/manpages && ${GMAKE} PREFIX=${PREFIX} manpages)
	(cd ${WRKSRC}/manpages && ${GMAKE} PREFIX=${PREFIX} MANPREFIX=${PREFIX}/man installman)
	(cd ${WRKSRC} && ${GMAKE} PREFIX=${PREFIX} installmanual)
	(cd ${WRKSRC}/misc && ${INSTALL_PROGRAM} striproff ${PREFIX}/bin/striproff)

.include <bsd.port.mk>
