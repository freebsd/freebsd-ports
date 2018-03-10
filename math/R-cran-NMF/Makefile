# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	NMF
PORTVERSION=	0.20.6
PORTREVISION=	2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Algorithms and Framework for Nonnegative Matrix Factorization

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-pkgmaker>=0.20:devel/R-cran-pkgmaker \
		R-cran-registry>0:devel/R-cran-registry \
		R-cran-rngtools>=1.2.3:devel/R-cran-rngtools \
		R-cran-stringr>=1.0.0:textproc/R-cran-stringr \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-gridBase>0:graphics/R-cran-gridBase \
		R-cran-colorspace>0:graphics/R-cran-colorspace \
		R-cran-RColorBrewer>0:graphics/R-cran-RColorBrewer \
		R-cran-foreach>0:devel/R-cran-foreach \
		R-cran-doParallel>0:devel/R-cran-doParallel \
		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-reshape2>0:devel/R-cran-reshape2

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
