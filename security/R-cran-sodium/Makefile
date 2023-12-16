PORTNAME=	sodium
DISTVERSION=	1.3.1
CATEGORIES=	security
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	R bindings to libsodium
WWW=		https://cran.r-project.org/web/packages/sodium/

LICENSE=	MIT

CRAN_DEPENDS=	libsodium>0:security/libsodium
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
