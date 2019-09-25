# $FreeBSD$

PORTNAME=	askpass
PORTVERSION=	1.1
CATEGORIES=	security
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Safe Password Entry for R, Git, and SSH

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-sys>0:devel/R-cran-sys
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
