PORTNAME=	matrixStats
DISTVERSION=	1.5.0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Functions that Apply to Rows and Columns of Matrices
WWW=		https://cran.r-project.org/web/packages/matrixStats/

LICENSE=	ART20

USES=		cran:auto-plist,compiles

pre-test:
# R-cran-R.rsp package does not exist yet
	@${LOCALBASE}/bin/Rscript -e 'install.packages("R.rsp", \
		repos = "https://cloud.r-project.org")'

.include <bsd.port.mk>
