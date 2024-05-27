PORTNAME=	textshaping
DISTVERSION=	0.4.0
CATEGORIES=	print
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Bindings to the 'HarfBuzz' and 'Fribidi' Libraries for Text Shaping
WWW=		https://github.com/r-lib/textshaping

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cpp11>=0.2.1:devel/R-cran-cpp11 \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-systemfonts>=1.1.0:devel/R-cran-systemfonts
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles pkgconfig

.include <bsd.port.mk>
