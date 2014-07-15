# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libfb
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	net net-mgmt
MASTER_SITES=	http://support.red-fone.com/downloads/fonulator/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	FoneBRIDGE configuration library

LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-shared
CPPFLAGS+=	${LIBNET_CPPFLAGS}
INSTALL_TARGET=	install-strip
USES=		libtool

LIBNET_CONFIG=	${LOCALBASE}/bin/libnet11-config
LIBNET_CPPFLAGS=`${LIBNET_CONFIG} --cflags` `${LIBNET_CONFIG} --defines`
LIBNET_LIBS=	`${LIBNET_CONFIG} --libs`

post-patch:
	@${REINPLACE_CMD} 's,-lnet,${LIBNET_LIBS},' ${WRKSRC}/configure

.include <bsd.port.mk>
