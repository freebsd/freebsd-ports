PORTNAME=	ps
DISTVERSION=	1.9.1
CATEGORIES=	sysutils
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	List, Query, Manipulate System Processes
WWW=		https://github.com/r-lib/ps

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-callr>0:devel/R-cran-callr \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-curl>0:ftp/R-cran-curl \
		R-cran-pillar>0:devel/R-cran-pillar \
		R-cran-pingr>0:net/R-cran-pingr \
		R-cran-processx>=3.1.0:sysutils/R-cran-processx \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		R-cran-webfakes>0:devel/R-cran-webfakes \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist,compiles

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/ps/bin/px

.include <bsd.port.mk>
