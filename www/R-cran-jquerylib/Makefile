PORTNAME=	jquerylib
PORTVERSION=	0.1.4
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Obtain 'jQuery' as an HTML Dependency Object

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-htmltools>0:textproc/R-cran-htmltools
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
