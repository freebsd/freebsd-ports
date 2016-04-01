# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	igraph
DISTVERSION=	1.0.1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Network Analysis and Visualization

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libgmp.so:math/gmp
RUN_DEPENDS=	R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-NMF>0:math/R-cran-NMF \
		R-cran-irlba>0:math/R-cran-irlba

USES=	cran:auto-plist
USE_GNOME=	libxml2

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: uses i386 assembler
.endif

.include <bsd.port.post.mk>
