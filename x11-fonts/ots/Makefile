# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ots
PORTVERSION=	8.0.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/khaledhosny/ots/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenType Sanitizer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libfreetype.so:print/freetype2 \
		libgtest.so:devel/googletest \
		liblz4.so:archivers/liblz4 \
		libwoff2dec.so:devel/woff2

USES=		compiler:c++11-lang meson pkgconfig shebangfix tar:xz

MESON_FALSE=	debug
MESON_TRUE=	graphite

SHEBANG_FILES=	tests/*.sh
bash_CMD=	${SH}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/meson.build

do-test:
	${SETENV} top_builddir=${BUILD_WRKSRC} top_srcdir=${WRKSRC} ${SH} ${WRKSRC}/tests/test_bad_fonts.sh
	${SETENV} top_builddir=${BUILD_WRKSRC} top_srcdir=${WRKSRC} ${SH} ${WRKSRC}/tests/test_fuzzed_fonts.sh
	${SETENV} top_builddir=${BUILD_WRKSRC} top_srcdir=${WRKSRC} ${SH} ${WRKSRC}/tests/test_good_fonts.sh

.include <bsd.port.mk>
