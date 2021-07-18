PORTNAME=	processx
DISTVERSION=	3.5.2
CATEGORIES=	sysutils
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Execute and Control System Processes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-R6>0:devel/R-cran-R6 \
		R-cran-ps>=1.2.0:sysutils/R-cran-ps
TEST_DEPENDS=	R-cran-callr>=3.2.0:devel/R-cran-callr \
		R-cran-cli>0:devel/R-cran-cli \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-curl>0:ftp/R-cran-curl

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
