PORTNAME=	CVST
DISTVERSION=	0.2-3
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Fast Cross-Validation via Sequential Testing
WWW=		https://cran.r-project.org/web/packages/CVST/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-kernlab>0:science/R-cran-kernlab
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
