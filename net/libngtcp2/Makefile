# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	ngtcp2
PORTVERSION=	0.6.0
CATEGORIES=	net
MASTER_SITES=	https://github.com/ngtcp2/ngtcp2/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	lib

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of QUIC protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++17-lang libtool pathfix pkgconfig ssl tar:xz

CONFIGURE_ARGS=	--enable-lib-only --with-jemalloc
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++17
USE_LDCONFIG=	yes

.include <bsd.port.mk>
