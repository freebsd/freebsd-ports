# Created by: arved
# $FreeBSD$

PORTNAME=	pcsc-tools
PORTVERSION=	1.5.6
CATEGORIES=	security
MASTER_SITES=	http://ludovic.rousseau.free.fr/softwares/pcsc-tools/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Tools to test a PCSC driver, card, or reader

LICENSE=	GPLv2

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
RUN_DEPENDS=	p5-PCSC-Card>=0:devel/p5-PCSC-Card \
		p5-Gtk3>=0:x11-toolkits/p5-Gtk3

USES=		gmake pkgconfig tar:bzip2

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
