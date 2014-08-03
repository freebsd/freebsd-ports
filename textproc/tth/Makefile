# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tth
PORTVERSION=	4.03
CATEGORIES=	textproc
MASTER_SITES=	http://hutchinson.belmont.ma.us/tth/tth-noncom/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	tth_C
EXTRACT_SUFX=	.tgz

MAINTAINER=	lx@FreeBSD.org
COMMENT=	TeX to HTML translator

RUN_DEPENDS=	ppmtogif:${PORTSDIR}/graphics/netpbm

USE_GHOSTSCRIPT_RUN=	yes
#USE_TEX=	latex

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} tth.c -o tth -ll

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tth ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/latex2gif ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ps2gif ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ps2png ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Xfonts.fix ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/license.txt ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/tth_manual.html ${STAGEDIR}${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${SED} -e "s,%%PREFIX%%,${PREFIX}," ${PKGMESSAGE}

.include <bsd.port.mk>
