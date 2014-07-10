# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ortp
PORTVERSION=	0.23.0
CATEGORIES=	net
MASTER_SITES=	SAVANNAH/linphone/ortp

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Real-time Transport Protocol (RTP) stack

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --disable-strict
CPPFLAGS+=	-DHAVE_DEV_RANDOM
INSTALL_TARGET=	install-strip
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.mk>
