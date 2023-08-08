PORTNAME=	bibtex
DISTVERSION=	0.5.1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Bibtex Parser
WWW=		https://cran.r-project.org/web/packages/bibtex/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-backports>=1.4.0:math/R-cran-backports
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
