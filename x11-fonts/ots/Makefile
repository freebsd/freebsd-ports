PORTNAME=	ots
PORTVERSION=	9.1.0
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/khaledhosny/ots/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenType Sanitizer
WWW=		https://github.com/khaledhosny/ots

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	brotli>=1.0.9:archivers/brotli \
		freetype2>=2.12.1:print/freetype2 \
		googletest>=1.11.0:devel/googletest \
		liblz4>=1.9.4:archivers/liblz4 \
		woff2>=1.0.2:devel/woff2
LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libfreetype.so:print/freetype2 \
		libgtest.so:devel/googletest \
		liblz4.so:archivers/liblz4 \
		libwoff2dec.so:devel/woff2

USES=		compiler:c++14-lang meson pkgconfig tar:xz

MESON_ARGS=	--default-library=both -Ddebug=false -Dgraphite=true -Dsynthesize-gvar=true
USE_CXXSTD=	c++14

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
