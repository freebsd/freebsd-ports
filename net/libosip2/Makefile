# $FreeBSD$

PORTNAME=	libosip2
PORTVERSION=	4.1.0
CATEGORIES=	net
MASTER_SITES=	GNU/osip

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Low layer of SIP implementation

LICENSE=	LGPL21

CONFIGURE_ARGS=	--disable-debug --disable-trace
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		pathfix pkgconfig

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS/s| help | |g" ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libosip2.so.11 ${STAGEDIR}${PREFIX}/lib/libosipparser2.so.11

.include <bsd.port.mk>
