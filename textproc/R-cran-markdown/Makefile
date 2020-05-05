# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	markdown
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Markdown Rendering for R

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-xfun>0:misc/R-cran-xfun \
		R-cran-mime>=0.3:misc/R-cran-mime
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
