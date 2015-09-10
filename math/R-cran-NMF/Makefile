# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	NMF
PORTVERSION=	0.20.6
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Algorithms and Framework for Nonnegative Matrix Factorization

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-pkgmaker>=0.20:${PORTSDIR}/devel/R-cran-pkgmaker \
		R-cran-registry>0:${PORTSDIR}/devel/R-cran-registry \
		R-cran-rngtools>=1.2.3:${PORTSDIR}/devel/R-cran-rngtools \
		R-cran-stringr>=1.0.0:${PORTSDIR}/textproc/R-cran-stringr \
		R-cran-digest>0:${PORTSDIR}/security/R-cran-digest \
		R-cran-gridBase>0:${PORTSDIR}/graphics/R-cran-gridBase \
		R-cran-colorspace>0:${PORTSDIR}/graphics/R-cran-colorspace \
		R-cran-RColorBrewer>0:${PORTSDIR}/graphics/R-cran-RColorBrewer \
		R-cran-foreach>0:${PORTSDIR}/devel/R-cran-foreach \
		R-cran-doParallel>0:${PORTSDIR}/devel/R-cran-doParallel \
		R-cran-ggplot2>0:${PORTSDIR}/graphics/R-cran-ggplot2 \
		R-cran-reshape2>0:${PORTSDIR}/devel/R-cran-reshape2

USES=	cran:auto-plist

.include <bsd.port.mk>
