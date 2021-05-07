PORTNAME=	fcft
DISTVERSION=	2.4.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://codeberg.org/dnkl/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple library for font loading and glyph rasterization

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

OPTIONS_DEFINE=	HARFBUZZ
OPTIONS_DEFAULT=HARFBUZZ

HARFBUZZ_DESC=		HarfBuzz for text shaping
HARFBUZZ_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
HARFBUZZ_MESON_ENABLED=	text-shaping

.include <bsd.port.mk>
