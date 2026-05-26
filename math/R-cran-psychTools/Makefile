PORTNAME=	psychTools
DISTVERSION=	2.6.4
CATEGORIES=	math science
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Tools to Accompany the 'psych' Package
WWW=		https://cran.r-project.org/package=psychTools

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-psych>0:math/R-cran-psych
TEST_DEPENDS=	R-cran-GPArotation>0:math/R-cran-GPArotation \
		R-cran-knitr>0:print/R-cran-knitr

USES=		cran:auto-plist

.include <bsd.port.mk>
