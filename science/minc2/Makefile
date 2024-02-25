PORTNAME=	minc
PORTVERSION=	2.2.00
DISTVERSIONPREFIX=	release-
PORTREVISION=	15
PORTEPOCH=	1
CATEGORIES=	science biology
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Medical Imaging NetCDF
WWW=		https://www.bic.mni.mcgill.ca/ServicesSoftware/MINC

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libnetcdf.so:science/netcdf
RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	BIC-MNI

MAKE_JOBS_UNSAFE=	yes

USES=		autoreconf bison gmake libtool perl5 shebangfix
SHEBANG_FILES=	progs/mincview/mincview
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-shared=yes --enable-static=yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CFLAGS+=	-Wno-error=return-type
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS=	minc-1* zh-tk

pre-patch:
	@${RM} ${WRKSRC}/ac_config_aux/*
	@${RM} ${WRKSRC}/progs/minccalc/gram.[ch]
	@${RM} ${WRKSRC}/progs/mincgen/ncgentab.[ch]

.include <bsd.port.mk>
