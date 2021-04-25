# Created by: TAKATSU Tomonari <tota@FreeBSD.org>

PORTNAME=	knitr
PORTVERSION=	1.33
CATEGORIES=	print
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	General-Purpose Package for Dynamic Report Generation in R

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-evaluate>=0.10:devel/R-cran-evaluate \
		R-cran-highr>0:textproc/R-cran-highr \
		R-cran-markdown>0:textproc/R-cran-markdown \
		R-cran-stringr>=0.6:textproc/R-cran-stringr \
		R-cran-yaml>=2.1.19:textproc/R-cran-yaml \
		R-cran-xfun>=0.21:misc/R-cran-xfun
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
