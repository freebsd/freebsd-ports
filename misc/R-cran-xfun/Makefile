PORTNAME=	xfun
DISTVERSION=	0.53
CATEGORIES=	misc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Miscellaneous Functions by Yihui Xie
WWW=		https://cran.r-project.org/package=xfun

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-commonmark>0:textproc/R-cran-commonmark \
		R-cran-curl>0:ftp/R-cran-curl \
		R-cran-data.table>0:devel/R-cran-data.table \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-knitr>=1.50:print/R-cran-knitr \
		R-cran-litedown>=0.6:textproc/R-cran-litedown \
		R-cran-magick>0:graphics/R-cran-magick \
		R-cran-mime>0:misc/R-cran-mime \
		R-cran-pak>0:devel/R-cran-pak \
		R-cran-remotes>0:devel/R-cran-remotes \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-testit>0:devel/R-cran-testit \
		R-cran-tinytex>=0.30:print/R-cran-tinytex \
		R-cran-xml2>0:textproc/R-cran-xml2 \
		R-cran-yaml>0:textproc/R-cran-yaml

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
