# Created by: jbacon

PORTNAME=	minc
PORTVERSION=	2.2.00
DISTVERSIONPREFIX=	release-
PORTREVISION=	11
PORTEPOCH=	1
CATEGORIES=	science biology
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Medical Imaging NetCDF

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: matrix_errno
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: matrix_errno

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libnetcdf.so:science/netcdf
RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	BIC-MNI

MAKE_JOBS_UNSAFE=	yes

USES=		autoreconf bison gmake libtool perl5 shebangfix
SHEBANG_FILES=	progs/mincview/mincview
GNU_CONFIGURE=	yes
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
