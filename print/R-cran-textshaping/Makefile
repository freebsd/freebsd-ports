PORTNAME=	textshaping
DISTVERSION=	1.0.3
CATEGORIES=	print
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	Bindings to the 'HarfBuzz' and 'Fribidi' Libraries for Text Shaping
WWW=		https://github.com/r-lib/textshaping

LICENSE=	MIT

BUILD_DEPENDS=	R-cran-cpp11>=0.2.1:devel/R-cran-cpp11 \
		R-cran-systemfonts>=1.0.0:devel/R-cran-systemfonts
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-stringi>0:textproc/R-cran-stringi \
		R-cran-systemfonts>=1.1.0:devel/R-cran-systemfonts
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		xorg-fonts-truetype>0:x11-fonts/xorg-fonts-truetype

USES=		cran:auto-plist,compiles pkgconfig

.include <bsd.port.mk>
