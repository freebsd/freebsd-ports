# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libfb
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	net net-mgmt
MASTER_SITES=	http://support.red-fone.com/downloads/fonulator/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	FoneBRIDGE configuration library

LIB_DEPENDS=	libnet.so:net/libnet

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-shared
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		libtool

.include <bsd.port.mk>
