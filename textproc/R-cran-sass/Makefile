PORTNAME=	sass
DISTVERSION=	0.4.8
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Syntactically Awesome Style Sheets ('Sass')
WWW=		https://cran.r-project.org/web/packages/sass/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-fs>0:sysutils/R-cran-fs \
		R-cran-htmltools>=0.5.1:textproc/R-cran-htmltools \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-rappdirs>0:devel/R-cran-rappdirs \
		R-cran-rlang>=0.4.10:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
