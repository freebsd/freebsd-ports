# New ports collection makefile for:	pcsc-tools
# Date created:				2012-01-20
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	pcsc-tools
PORTVERSION=	1.4.18
CATEGORIES=	security
MASTER_SITES=	http://ludovic.rousseau.free.fr/softwares/pcsc-tools/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Tools to test a PCSC driver, card, or reader

LICENSE=	GPLv2

LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite
RUN_DEPENDS=	p5-PCSC-Card>=0:${PORTSDIR}/devel/p5-PCSC-Card

USE_GMAKE=	yes

MAN1=		pcsc_scan.1 gscriptor.1p scriptor.1p ATR_analysis.1p

post-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/$i ${MAN1PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
