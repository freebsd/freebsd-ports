# Created by: TAKATSU Tomonari <tota@FreeBSD.org>

PORTNAME=	htmltools
PORTVERSION=	0.5.2
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tools for HTML generation and output

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-digest>0:security/R-cran-digest \
		R-cran-base64enc>0:converters/R-cran-base64enc \
		R-cran-rlang>=0.4.10:devel/R-cran-rlang \
		R-cran-fastmap>0:databases/R-cran-fastmap
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
