PORTNAME=	xfun
DISTVERSION=	0.47
CATEGORIES=	misc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Miscellaneous Functions by Yihui Xie
WWW=		https://cran.r-project.org/web/packages/xfun/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-curl>0:ftp/R-cran-curl \
		R-cran-htmltools>0:textproc/R-cran-htmltools \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-knitr>=1.47:print/R-cran-knitr \
		R-cran-magick>0:graphics/R-cran-magick \
		R-cran-markdown>0:textproc/R-cran-markdown \
		R-cran-mime>0:misc/R-cran-mime \
		R-cran-pak>0:devel/R-cran-pak \
		R-cran-remotes>0:devel/R-cran-remotes \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-testit>0:devel/R-cran-testit \
		R-cran-tinytex>=0.30:print/R-cran-tinytex \
		R-cran-xml2>0:textproc/R-cran-xml2 \
		R-cran-yaml>0:textproc/R-cran-yaml

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
