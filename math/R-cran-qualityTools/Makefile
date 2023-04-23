PORTNAME=	qualityTools
DISTVERSION=	1.55
PORTREVISION=	5
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Statistical Methods for Quality Science
WWW=		http://www.r-qualitytools.org/

LICENSE=	GPLv2

BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

CRAN_DEPENDS=	R-cran-Rsolnp>0:math/R-cran-Rsolnp

USES=	cran:auto-plist

.include <bsd.port.mk>
