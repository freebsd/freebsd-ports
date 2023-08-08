PORTNAME=	markdown
PORTVERSION=	1.7
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Markdown Rendering for R
WWW=		https://cran.r-project.org/web/packages/markdown/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-commonmark>=1.9.0:textproc/R-cran-commonmark \
		R-cran-xfun>=0.38:misc/R-cran-xfun
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
