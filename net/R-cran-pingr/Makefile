PORTNAME=	pingr
DISTVERSION=	2.0.5
CATEGORIES=	net
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Check if a Remote Computer is Up
WWW=		https://cran.r-project.org/web/packages/pingr/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-processx>0:sysutils/R-cran-processx
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
