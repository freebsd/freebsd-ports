PORTNAME=	magic
DISTVERSION=	1.6-0
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Create and Investigate Magic Squares
WWW=		https://cran.r-project.org/web/packages/magic/

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-abind>0:devel/R-cran-abind
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
