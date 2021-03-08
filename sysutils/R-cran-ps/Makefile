# $FreeBSD$

PORTNAME=	ps
DISTVERSION=	1.6.0
CATEGORIES=	sysutils
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	List, Query, Manipulate System Processes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-R6>0:devel/R-cran-R6 \
		R-cran-callr>0:devel/R-cran-callr \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-curl>0:ftp/R-cran-curl \
		R-cran-processx>=3.1.0:sysutils/R-cran-processx

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
