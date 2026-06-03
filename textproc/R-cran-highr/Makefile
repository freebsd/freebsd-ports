PORTNAME=	highr
DISTVERSION=	0.12
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Syntax Highlighting for R Source Code
WWW=		https://cran.r-project.org/web/packages/highr/

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-xfun>=0.18:misc/R-cran-xfun
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-markdown>0:textproc/R-cran-markdown \
		R-cran-testit>0:devel/R-cran-testit

USES=		cran:auto-plist

.include <bsd.port.mk>
