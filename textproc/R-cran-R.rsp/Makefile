PORTNAME=	R.rsp
DISTVERSION=	0.46.0
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Dynamic Generation of Scientific Reports
WWW=		https://cran.r-project.org/package=R.rsp

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	multi

RUN_DEPENDS=	R-cran-digest>0:security/R-cran-digest \
		R-cran-R.cache>0:devel/R-cran-R.cache \
		R-cran-R.methodsS3>=1.8.0:devel/R-cran-R.methodsS3 \
		R-cran-R.oo>=1.23.0:devel/R-cran-R.oo \
		R-cran-R.utils>0:devel/R-cran-R.utils
TEST_DEPENDS=	R-cran-base64enc>0:converters/R-cran-base64enc \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-markdown>0:textproc/R-cran-markdown \
		R-cran-R.devices>0:graphics/R-cran-R.devices

USES=		cran:auto-plist shebangfix

SHEBANG_FILES=	inst/tcl/r-httpd.tcl

.include <bsd.port.mk>
