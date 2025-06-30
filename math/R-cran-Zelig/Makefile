PORTNAME=	Zelig
DISTVERSION=	5.1.7
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Everyone's Statistical Software
WWW=		https://gking.harvard.edu/zelig

LICENSE=	GPLv3+

DEPRECATED=	Depends on expirnig finance/R-cran-AER
EXPIRATION_DATE=2025-09-30

BUILD_DEPENDS=	R-cran-AER>=0:finance/R-cran-AER \
		R-cran-Amelia>=0:math/R-cran-Amelia \
		R-cran-sandwich>=0:math/R-cran-sandwich \
		R-cran-VGAM>=0:math/R-cran-VGAM \
		R-cran-plyr>=0:devel/R-cran-plyr \
		R-cran-quantreg>=0:math/R-cran-quantreg \
		R-cran-MCMCpack>=0:math/R-cran-MCMCpack \
		R-cran-maxLik>=0:math/R-cran-maxLik \
		R-cran-jsonlite>=0:converters/R-cran-jsonlite \
		R-cran-dplyr>=0:math/R-cran-dplyr \
		R-cran-MatchIt>=0:math/R-cran-MatchIt \
		R-cran-geepack>=0:math/R-cran-geepack \
		R-cran-survey>=0:math/R-cran-survey
RUN_DEPENDS=	R-cran-AER>=0:finance/R-cran-AER \
		R-cran-Amelia>=0:math/R-cran-Amelia \
		R-cran-sandwich>=0:math/R-cran-sandwich \
		R-cran-VGAM>=0:math/R-cran-VGAM \
		R-cran-plyr>=0:devel/R-cran-plyr \
		R-cran-quantreg>=0:math/R-cran-quantreg \
		R-cran-MCMCpack>=0:math/R-cran-MCMCpack \
		R-cran-maxLik>=0:math/R-cran-maxLik \
		R-cran-jsonlite>=0:converters/R-cran-jsonlite \
		R-cran-dplyr>=0:math/R-cran-dplyr \
		R-cran-MatchIt>=0:math/R-cran-MatchIt \
		R-cran-geepack>=0:math/R-cran-geepack \
		R-cran-survey>=0:math/R-cran-survey

USES=		cran:auto-plist

.include <bsd.port.mk>
