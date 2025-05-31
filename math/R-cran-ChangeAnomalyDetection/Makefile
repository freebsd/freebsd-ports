PORTNAME=	ChangeAnomalyDetection
PORTVERSION=	0.1.0
PORTREVISION=	11
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Change Anomaly Detection
WWW=		https://cran.r-project.org/web/packages/ChangeAnomalyDetection/

LICENSE=	BSDunclear
LICENSE_NAME=	Unclear BSD License
LICENSE_TEXT=	License of this software is declared as 'BSD' in DESCRIPTION. \
		But it is not clear which versions of the BSD license (2, \
		3 or 4 clause) it is. No further file in the source archive \
		contains license information.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	R-cran-TTR>0:finance/R-cran-TTR \
		R-cran-forecast>0:math/R-cran-forecast

USES=	cran:auto-plist

.include <bsd.port.mk>
