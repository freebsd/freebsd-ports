PORTNAME=	maps
DISTVERSION=	3.4.4
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Draw Geographical Maps
WWW=		https://cran.r-project.org/package=maps

LICENSE=	GPLv2

TEST_DEPENDS=	R-cran-sp>0:math/R-cran-sp

USES=		cran:auto-plist,compiles

pre-test:
# R-cran-mapproj package does not exist yet
	@${LOCALBASE}/bin/Rscript -e 'install.packages("mapproj", \
		repos = "https://cloud.r-project.org")'

.include <bsd.port.mk>
