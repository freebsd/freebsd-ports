PORTNAME=	tinytex
DISTVERSION=	0.41
PORTREVISION=	1
CATEGORIES=	print
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Helper functions to maintain LaTeX distribution
WWW=		https://cran.r-project.org/web/packages/tinytex/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-xfun>=0.29:misc/R-cran-xfun
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
