PORTNAME=	textshaping
DISTVERSION=	0.3.7
CATEGORIES=	print
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Bindings to the 'HarfBuzz' and 'Fribidi' Libraries for Text Shaping
WWW=		https://github.com/r-lib/textshaping

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-systemfonts>=1.0.0:devel/R-cran-systemfonts
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles pkgconfig

.include <bsd.port.mk>
