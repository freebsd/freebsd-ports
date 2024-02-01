PORTNAME=	commonmark
DISTVERSION=	1.9.1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	High Performance CommonMark and Github Markdown Rendering in R
WWW=		https://cran.r-project.org/web/packages/commonmark/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-xml2>0:textproc/R-cran-xml2

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
