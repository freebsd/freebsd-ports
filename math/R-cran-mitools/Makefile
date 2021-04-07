PORTNAME=	mitools
DISTVERSION=	2.4
PORTREVISION=	2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Tools for Multiple Imputation of Missing Data

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-DBI>=0:databases/R-cran-DBI
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
