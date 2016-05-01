# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rmarkdown
PORTVERSION=	0.9.6
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Dynamic Documents for R

LICENSE=	GPLv3

RUN_DEPENDS=	hs-pandoc>=1.12.3:textproc/hs-pandoc \
		R-cran-knitr>=1.12:print/R-cran-knitr \
		R-cran-yaml>=2.1.5:textproc/R-cran-yaml \
		R-cran-htmltools>=0.2.4:textproc/R-cran-htmltools \
		R-cran-caTools>0:devel/R-cran-caTools

USES=	cran:auto-plist

.include <bsd.port.mk>
