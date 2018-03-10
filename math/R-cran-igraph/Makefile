# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	igraph
DISTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Network Analysis and Visualization

LICENSE=	GPLv2+

LIB_DEPENDS=	libgmp.so:math/gmp
CRAN_DEPENDS=	R-cran-irlba>0:math/R-cran-irlba \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-pkgconfig>=2.0.0:devel/R-cran-pkgconfig
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles
USE_GNOME=	libxml2

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: uses i386 assembler
.endif

.include <bsd.port.post.mk>
