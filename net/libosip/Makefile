# Created by: ijliao
# $FreeBSD$

PORTNAME=	libosip
PORTVERSION=	3.6.0
CATEGORIES=	net
MASTER_SITES=	GNU/osip
DISTNAME=	${PORTNAME}2-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A low layer of SIP implementation

CONFLICTS=	libosip2-2*

USES=		pathfix pkgconfig
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-debug --disable-trace
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "/^SUBDIRS/s| help | |g" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
