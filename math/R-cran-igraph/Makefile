PORTNAME=	igraph
DISTVERSION=	2.1.4
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Network Analysis and Visualization
WWW=		https://cran.r-project.org/web/packages/igraph/

LICENSE=	GPLv2+

LIB_DEPENDS=	libglpk.so:math/glpk
RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-cpp11>=0.5.0:devel/R-cran-cpp11 \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-pkgconfig>=2.0.0:devel/R-cran-pkgconfig \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-vctrs>0:devel/R-cran-vctrs

USES=		compiler:c++11-lang cran:auto-plist,compiles gnome
USE_GNOME=	libxml2

.include <bsd.port.mk>
