# New ports collection makefile for:    tth
# Date created:         19 Feb 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tth
PORTVERSION=	3.85
CATEGORIES=	textproc
MASTER_SITES=	http://hutchinson.belmont.ma.us/tth/tth-noncom/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	tth_C
EXTRACT_SUFX=	.tgz

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A TeX to HTML translator

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		ppmtogif:${PORTSDIR}/graphics/netpbm

USE_GHOSTSCRIPT_RUN=	yes

MAN1=		tth.1

PLIST_FILES=	bin/latex2gif bin/ps2gif bin/ps2png bin/tth bin/Xfonts.fix
PORTDOCS=	license.txt tth_manual.html

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} tth.c -o tth -ll

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tth ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/latex2gif ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ps2gif ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ps2png ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Xfonts.fix ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tth.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/tth_manual.html ${DOCSDIR}
.endif
	@${SED} -e "s,%%PREFIX%%,${PREFIX}," ${PKGMESSAGE}

.include <bsd.port.mk>
