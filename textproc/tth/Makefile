# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tth
PORTVERSION=	4.03
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://hutchinson.belmont.ma.us/tth/tth-noncom/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	tth_C

MAINTAINER=	lx@FreeBSD.org
COMMENT=	TeX to HTML translator

RUN_DEPENDS=	ppmtogif:graphics/netpbm

USES=		ghostscript:run shebangfix tar:tgz
#USE_TEX=	latex
SHEBANG_FILES=	Xfonts.fix

OPTIONS_DEFINE=	DOCS

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

.include <bsd.port.mk>
