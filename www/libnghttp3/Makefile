# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nghttp3
PORTVERSION=	0.1.0.g20200629
CATEGORIES=	www net
PKGNAMEPREFIX=	lib

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/3 C Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++17-lang libtool pathfix pkgconfig

CONFIGURE_ARGS=	--enable-lib-only
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++17
USE_LDCONFIG=	yes

GH_ACCOUNT=	ngtcp2
GH_TAGNAME=	6c926bb
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|0.1.0-DEV|${PORTVERSION}|' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
