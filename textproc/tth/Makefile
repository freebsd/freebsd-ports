# New ports collection makefile for:    tth
# Version required:     2.22
# Date created:         19 Feb 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=       tth_C
PKGNAME=	tth-2.22
CATEGORIES=	textproc
MASTER_SITES=	http://www.freebsd.org/~tg/ \
		http://hutchinson.belmont.ma.us/tth/tth-noncom/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript5 \
		ppmtogif:${PORTSDIR}/graphics/netpbm \
		latex:${PORTSDIR}/print/teTeX

MAN1=		tth.1

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} tth.c -o tth -ll

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tth ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/l2h ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/latex2gif ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ps2gif ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tth.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/tth
	${INSTALL_SCRIPT} ${WRKSRC}/license.txt ${PREFIX}/share/doc/tth
.if !defined(NOPORTDOCS)
	${INSTALL_SCRIPT} ${WRKSRC}/tth_manual.html ${PREFIX}/share/doc/tth
.endif
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
