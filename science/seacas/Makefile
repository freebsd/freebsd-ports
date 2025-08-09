PORTNAME=	seacas
DISTVERSIONPREFIX=	v
DISTVERSION=	2025-03-13
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Sandia Engineering Analysis Code Access System (SEACAS)
WWW=		https://sandialabs.github.io/seacas-docs/sphinx/html/index.html \
		https://github.com/sandialabs/seacas

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libhdf5.so:science/hdf5 \
		libmatio.so:math/matio \
		libnetcdf.so:science/netcdf

USES=		cmake fortran localbase:ldflags python shebangfix xorg
USE_XORG=	x11
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sandialabs

SHEBANG_FILES=	packages/seacas/scripts/decomp.in \
		packages/seacas/scripts/epup.in \
		packages/seacas/scripts/pconjoin.in
SHEBANG_GLOB=	*.py

CMAKE_ON=	Seacas_ENABLE_ALL_PACKAGES \
		Seacas_ENABLE_ALL_OPTIONAL_PACKAGES \
		Seacas_ENABLE_SECONDARY_TESTED_CODE \
		BUILD_SHARED_LIBS

LDFLAGS+=	-lhdf5 # https://github.com/sandialabs/seacas/issues/538

.include <bsd.port.mk>
