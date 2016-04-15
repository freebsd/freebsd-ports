# Created by: arved
# $FreeBSD$

PORTNAME=	pcsc-tools
PORTVERSION=	1.4.26
CATEGORIES=	security
MASTER_SITES=	http://ludovic.rousseau.free.fr/softwares/pcsc-tools/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Tools to test a PCSC driver, card, or reader

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENCE

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
RUN_DEPENDS=	p5-PCSC-Card>=0:devel/p5-PCSC-Card \
		p5-Gtk2>=0:x11-toolkits/p5-Gtk2

USES=		gmake pkgconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcsc_scan \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/ATR_analysis \
		${WRKSRC}/gscriptor \
		${WRKSRC}/scriptor \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/pcsc_scan.1 \
		${WRKSRC}/gscriptor.1p \
		${WRKSRC}/scriptor.1p \
		${WRKSRC}/ATR_analysis.1p \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/pcsc
	${INSTALL_DATA} ${WRKSRC}/smartcard_list.txt \
		${STAGEDIR}/${PREFIX}/share/pcsc

.include <bsd.port.mk>
