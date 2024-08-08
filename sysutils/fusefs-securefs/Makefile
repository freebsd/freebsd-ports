PORTNAME=	securefs
DISTVERSION=	0.14.3
PORTREVISION=	1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filesystem in userspace with transparent encryption and decryption
WWW=		https://github.com/netheril96/securefs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${LOCALBASE}/include/tclap/TCLAPConfig.h:devel/tclap
LIB_DEPENDS=	libutf8proc.so:textproc/utf8proc \
		libargon2.so:security/libargon2 \
		libjsoncpp.so:devel/jsoncpp \
		libcryptopp.so:security/cryptopp \
		libabsl_strings.so:devel/abseil

USES=		cmake compiler:c++17-lang fuse pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	netheril96

PLIST_FILES=	bin/securefs

CMAKE_OFF=	SECUREFS_ENABLE_BUILD_TEST \
		SECUREFS_ENABLE_UNIT_TEST \
		SECUREFS_USE_VCPKG
CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17

.include <bsd.port.mk>
