# Created by: TAKATSU Tomonari <tota@FreeBSD.org>

PORTNAME=	rmarkdown
PORTVERSION=	2.8
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Dynamic Documents for R

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-knitr>=1.22:print/R-cran-knitr \
		R-cran-yaml>=2.1.19:textproc/R-cran-yaml \
		R-cran-htmltools>=0.3.5:textproc/R-cran-htmltools \
		R-cran-evaluate>=0.13:devel/R-cran-evaluate \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-tinytex>=0.31:print/R-cran-tinytex \
		R-cran-xfun>=0.21:misc/R-cran-xfun \
		R-cran-stringr>=1.2.0:textproc/R-cran-stringr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	hs-pandoc>=1.14:textproc/hs-pandoc \
		${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
