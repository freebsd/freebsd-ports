# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ngtcp2
PORTVERSION=	0.1.0.g20200629
CATEGORIES=	net
PKGNAMEPREFIX=	lib

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementment of QUIC protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++17-lang libtool pathfix pkgconfig

CONFIGURE_ARGS=	--enable-lib-only
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++17
USE_LDCONFIG=	yes

GH_TAGNAME=	d6ba5c6
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|0.1.0-DEV|${PORTVERSION}|' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
