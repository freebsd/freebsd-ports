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
COMMENT=	A TeX to HTML translator

.if defined(WITH_GHOSTSCRIPT_AFPL) && ${WITH_GHOSTSCRIPT_AFPL} == yes
GSPORT?=	print/ghostscript-afpl
.else
GSPORT?=	print/ghostscript-gnu
.endif

RUN_DEPENDS=	gs:${PORTSDIR}/${GSPORT} \
		latex:${PORTSDIR}/print/teTeX \
		ppmtogif:${PORTSDIR}/graphics/netpbm

MAN1=		tth.1

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} tth.c -o tth -ll

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tth ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/l2h ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/latex2gif ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ps2gif ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ps2png ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tth.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/tth_manual.html ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
