PORTNAME=	processx
DISTVERSION=	3.8.6
CATEGORIES=	sysutils
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Execute and Control System Processes
WWW=		https://processx.r-lib.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-ps>=1.2.0:sysutils/R-cran-ps \
		R-cran-R6>0:devel/R-cran-R6
TEST_DEPENDS=	R-cran-callr>=3.7.3:devel/R-cran-callr \
		R-cran-cli>=3.3.0:devel/R-cran-cli \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-curl>0:ftp/R-cran-curl \
		R-cran-rlang>=1.0.2:devel/R-cran-rlang \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		R-cran-webfakes>0:devel/R-cran-webfakes \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist,compiles

TESTING_UNSAFE=	Fail because of wrong R-cran-ps (see PR280006)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/processx/bin/px
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/processx/bin/sock
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/processx/bin/supervisor
.include <bsd.port.mk>
