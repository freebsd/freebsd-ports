PORTNAME=	libfido2
PORTVERSION=	1.11.0
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/libfido2/Releases/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides library functionality for FIDO 2.0

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcbor.so:devel/libcbor

USES=		cmake compiler:c11 pkgconfig ssl

CMAKE_OFF=	FUZZ LIBFUZZER NFC_LINUX USE_HIDAPI USE_WINHELLO
CMAKE_ON=	BUILD_EXAMPLES BUILD_MANPAGES BUILD_SHARED_LIBS BUILD_STATIC_LIBS BUILD_TOOLS

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

# we do not ship libcrypto.pc in base system
.if ${SSL_DEFAULT} == base
EXTRA_PATCHES+= ${PATCHDIR}/extra-patch-openssl
.endif

.include <bsd.port.post.mk>
