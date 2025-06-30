PORTNAME=	xml2
PORTVERSION=	1.3.8
PORTREVISION=	1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Parse XML
WWW=		https://cran.r-project.org/web/packages/xml2/

LICENSE=	MIT

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang

USES=		cran:auto-plist,compiles gnome
USE_GNOME=	libxml2

.include <bsd.port.mk>
