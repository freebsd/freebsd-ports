# $FreeBSD$

PORTNAME=	libosip2
PORTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	GNU/osip

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Low layer of SIP implementation

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug --disable-trace
INSTALL_TARGET=	install-strip
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS/s| help | |g" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
