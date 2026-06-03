PORTNAME=	yaml
DISTVERSION=	2.3.12
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Methods to convert R data to YAML and back
WWW=		https://cran.r-project.org/package=yaml

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		compiler:c++23-lang cran:auto-plist,compiles

.include <bsd.port.mk>
