PORTNAME=	xopen
DISTVERSION=	1.0.0
CATEGORIES=	sysutils
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Open System Files, 'URLs', Anything

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-processx>0:sysutils/R-cran-processx
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-ps>0:sysutils/R-cran-ps

USES=		cran:auto-plist

.include <bsd.port.mk>
