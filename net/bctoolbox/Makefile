# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bctoolbox
PORTVERSION=	0.2.0
CATEGORIES=	net
MASTER_SITES=	SAVANNAH/linphone/bctoolbox

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Belledonne Communications utility library

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	mbedtls>=2.3.0_2:security/mbedtls
LIB_DEPENDS=	libmbedtls.so.10:security/mbedtls

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-strict
CPPFLAGS+=	-DHAVE_ARC4RANDOM -DHAVE_DTLS_SRTP
INSTALL_TARGET=	install-strip
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/bctoolbox-tester.pc

.include <bsd.port.mk>
