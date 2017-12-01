# $FreeBSD$

PORTNAME=	libosip2
PORTVERSION=	5.0.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	GNU/osip

MAINTAINER=	bofh@FreeBSD.org
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
