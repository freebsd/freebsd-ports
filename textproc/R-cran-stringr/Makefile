# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stringr
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Make it easier to work with strings

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-glue>=1.2.0:devel/R-cran-glue \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-stringi>=1.1.7:textproc/R-cran-stringi
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
