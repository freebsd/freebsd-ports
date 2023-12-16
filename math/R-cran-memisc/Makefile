PORTNAME=	memisc
DISTVERSION=	0.99.31.7
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Provides an infrastructure for the management of survey data
WWW=		https://www.elff.eu/software/memisc/

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-data.table>0:devel/R-cran-data.table \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-yaml>0:textproc/R-cran-yaml

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
