PORTNAME=	DoE.base
DISTVERSION=	1.2-4
CATEGORIES=	math devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Full Factorials, Orthogonal Arrays and Base Utilities for DoE
WWW=		https://CRAN.R-project.org/package=DoE.base

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-combinat>0:math/R-cran-combinat \
		R-cran-conf.design>1:math/R-cran-conf.design \
		R-cran-numbers>=0:math/R-cran-numbers \
		R-cran-partitions>=0:math/R-cran-partitions \
		R-cran-vcd>0:devel/R-cran-vcd
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
