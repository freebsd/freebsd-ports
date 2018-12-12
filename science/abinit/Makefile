# Created by: NAKATA Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abinit
DISTVERSION=	8.8.4
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	https://www.abinit.org/sites/default/files/packages/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Full-featured atomic-scale first-principles simulation software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	liblapack.so:math/lapack \
		libblas.so:math/blas
RUN_DEPENDS=	atompaw:science/atompaw

USES=		fortran gmake localbase:ldflags
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static

FCFLAGS+=	-ffree-line-length-none

.include <bsd.port.mk>
