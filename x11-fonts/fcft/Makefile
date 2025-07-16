PORTNAME=	fcft
DISTVERSION=	3.3.2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://codeberg.org/dnkl/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple library for font loading and glyph rasterization
WWW=		https://codeberg.org/dnkl/fcft

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	tllist>=1.0.1:devel/tllist \
		scdoc:textproc/scdoc
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		compiler:c11 meson pkgconfig xorg
USE_LDCONFIG=	yes
USE_XORG=	pixman
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS HARFBUZZ UTF8PROC
OPTIONS_DEFAULT=HARFBUZZ UTF8PROC

DOCS_BUILD_DEPENDS=	scdoc:textproc/scdoc
DOCS_MESON_ENABLED=	docs

HARFBUZZ_DESC=		Shaping of individual grapheme clusters via HarfBuzz
HARFBUZZ_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
HARFBUZZ_MESON_ENABLED=	grapheme-shaping

UTF8PROC_DESC=		Shaping of whole text runs via libutf8proc
UTF8PROC_LIB_DEPENDS=	libutf8proc.so:textproc/utf8proc
UTF8PROC_MESON_ENABLED=	run-shaping
UTF8PROC_IMPLIES=	HARFBUZZ

.include <bsd.port.mk>
