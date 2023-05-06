PORTNAME=	ots
PORTVERSION=	9.0.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/khaledhosny/ots/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenType Sanitizer
WWW=		https://github.com/khaledhosny/ots

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	meson>=0.55.2:devel/meson
LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libfreetype.so:print/freetype2 \
		libgtest.so:devel/googletest \
		liblz4.so:archivers/liblz4 \
		libwoff2dec.so:devel/woff2

USES=		compiler:c++14-lang meson pkgconfig tar:xz
USE_CXXSTD=	c++14 # googletest 1.13

MESON_ARGS=	--default-library=both -Ddebug=false -Dgraphite=true

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
