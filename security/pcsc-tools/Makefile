# Created by: arved
# $FreeBSD$

PORTNAME=	pcsc-tools
PORTVERSION=	1.4.21
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://ludovic.rousseau.free.fr/softwares/pcsc-tools/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Tools to test a PCSC driver, card, or reader

LICENSE=	GPLv2

LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite
RUN_DEPENDS=	p5-PCSC-Card>=0:${PORTSDIR}/devel/p5-PCSC-Card \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2

USES=		gmake pkgconfig

MAN1=		pcsc_scan.1 gscriptor.1p scriptor.1p ATR_analysis.1p

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e "s,DESTDIR,PREFIX,g" ${WRKSRC}/Makefile

post-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/$i ${MAN1PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
