# Created by: ijliao
# $FreeBSD$

PORTNAME=	libosip
PORTVERSION=	3.6.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	GNU/osip
DISTNAME=	${PORTNAME}2-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Low layer of SIP implementation

CONFLICTS=	libosip2-2*

DEPRECATED=	Superseded by net/libosip2
EXPIRATION_DATE=2014-08-31

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug --disable-trace
INSTALL_TARGET=	install-strip
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS/s| help | |g" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
