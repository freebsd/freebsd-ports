# New ports collection makefile for:    tth
# Date created:         19 Feb 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tth
PORTVERSION=	3.59
CATEGORIES=	textproc
MASTER_SITES=	http://hutchinson.belmont.ma.us/tth/tth-noncom/
DISTNAME=	tth_C
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A TeX to HTML translator

USE_GHOSTSCRIPT_RUN=	yes

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		ppmtogif:${PORTSDIR}/graphics/netpbm

MAN1=		tth.1

PLIST_FILES=	bin/latex2gif bin/ps2gif bin/ps2png bin/tth
PORTDOCS=	license.txt tth_manual.html

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} tth.c -o tth -ll

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tth ${PREFIX}/bin
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
