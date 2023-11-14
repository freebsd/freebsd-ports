PORTNAME=	libfido2
PORTVERSION=	1.14.0
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/libfido2/Releases/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides library functionality for FIDO 2.0
WWW=		https://developers.yubico.com/libfido2/ \
		https://github.com/Yubico/libfido2

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcbor.so:devel/libcbor

USES=		cmake compiler:c11 pathfix pkgconfig ssl

CFLAGS+=	-DOPENSSL_API_COMPAT=0x10100000L
CMAKE_OFF=	FUZZ LIBFUZZER NFC_LINUX USE_HIDAPI USE_WINHELLO
CMAKE_ON=	BUILD_EXAMPLES BUILD_MANPAGES BUILD_SHARED_LIBS BUILD_STATIC_LIBS BUILD_TOOLS

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

# Skip libcrypto.pc while using OpenSSL from base system on older FreeBSD versions which does not skip this file
.if ${SSL_DEFAULT} == base && !exists(/usr/libdata/pkgconfig/libcrypto.pc)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-openssl
.endif

.include <bsd.port.post.mk>
