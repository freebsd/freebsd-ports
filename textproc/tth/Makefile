# New ports collection makefile for:    tth
# Date created:         19 Feb 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tth
PORTVERSION=	2.78
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://hutchinson.belmont.ma.us/tth/tth-noncom/
MASTER_SITE_SUBDIR=	tg
DISTNAME=	tth_C
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript6 \
		latex:${PORTSDIR}/print/teTeX \
		ppmtogif:${PORTSDIR}/graphics/netpbm

MAN1=		tth.1

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} tth.c -o tth -ll

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tth ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/l2h ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/latex2gif ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ps2gif ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ps2png ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tth.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/tth
	${INSTALL_SCRIPT} ${WRKSRC}/license.txt ${PREFIX}/share/doc/tth
.if !defined(NOPORTDOCS)
	${INSTALL_SCRIPT} ${WRKSRC}/tth_manual.html ${PREFIX}/share/doc/tth
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
