PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	4.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open-source C++ library for RTP/SRTP media delivery
WWW=		https://ultravideo.fi/uvgrtp.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcryptopp.so:security/cryptopp

USES=		cmake compiler:c++17-lang pkgconfig
CMAKE_ARGS=	-DPKG_CONFIG_PATH:STRING=libdata/pkgconfig
CMAKE_ON=	UVGRTP_BUILD_SHARED UVGRTP_DISABLE_EXAMPLES \
		UVGRTP_DISABLE_TESTS UVGRTP_RELEASE_COMMIT
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ultravideo
GH_PROJECT=	uvgRTP

post-patch:
	@${REINPLACE_CMD} -e 's, @CRYPTOPP_INCLUDE_DIRS@,,' \
		${WRKSRC}/cmake/uvgrtp.pc.in

.include <bsd.port.mk>
