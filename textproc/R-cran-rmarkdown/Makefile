# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rmarkdown
PORTVERSION=	1.0
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Dynamic Documents for R

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-knitr>=1.13:print/R-cran-knitr \
		R-cran-yaml>=2.1.5:textproc/R-cran-yaml \
		R-cran-htmltools>=0.2.4:textproc/R-cran-htmltools \
		R-cran-caTools>0:devel/R-cran-caTools \
		R-cran-base64enc>0:converters/R-cran-base64enc \
		R-cran-jsonlite>0:converters/R-cran-jsonlite
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	hs-pandoc>=1.12.3:textproc/hs-pandoc \
		${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
