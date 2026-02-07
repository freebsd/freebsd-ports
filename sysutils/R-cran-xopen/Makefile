PORTNAME=	xopen
DISTVERSION=	1.0.1
CATEGORIES=	sysutils
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Open System Files, 'URLs', Anything
WWW=		https://github.com/r-lib/xopen

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-processx>0:sysutils/R-cran-processx
TEST_DEPENDS=	R-cran-ps>0:sysutils/R-cran-ps \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
