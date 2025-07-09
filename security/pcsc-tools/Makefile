PORTNAME=	pcsc-tools
PORTVERSION=	1.7.3
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	https://pcsc-tools.apdu.fr/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Tools to test a PCSC driver, card, or reader
WWW=		https://pcsc-tools.apdu.fr/

LICENSE=	GPLv2

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
RUN_DEPENDS=	p5-PCSC-Card>=0:devel/p5-PCSC-Card \
		p5-Gtk3>=0:x11-toolkits/p5-Gtk3

USES=		gmake pkgconfig tar:bzip2 gettext-tools

LDFLAGS+=	-pthread
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
