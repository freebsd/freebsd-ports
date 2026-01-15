PORTNAME=	libfido2
PORTVERSION=	1.16.0
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/libfido2/Releases/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides library functionality for FIDO 2.0
WWW=		https://developers.yubico.com/libfido2/ \
		https://github.com/Yubico/libfido2

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcbor.so:devel/libcbor

USES=		cmake:testing compiler:c11 pkgconfig ssl

CFLAGS+=	-DOPENSSL_API_COMPAT=0x10100000L
CMAKE_OFF=	BUILD_TESTS \
		FUZZ \
		NFC_LINUX \
		USE_HIDAPI \
		USE_PCSC \
		USE_WINHELLO
CMAKE_ON=	BUILD_EXAMPLES \
		BUILD_MANPAGES \
		BUILD_SHARED_LIBS \
		BUILD_STATIC_LIBS \
		BUILD_TOOLS
CMAKE_TESTING_ON=	BUILD_TESTS

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
