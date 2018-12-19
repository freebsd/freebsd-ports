# $FreeBSD$

PORTNAME=	h5z-zfp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Registered ZFP compression plugin for HDF5

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libzfp.so:devel/zfp

USES=		gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	${PORTNAME:tu}
USE_LDCONFIG=	yes

MAKE_ARGS=	SHELL=${LOCALBASE}/bin/bash \
		HDF5_HOME=${STAGEDIR}${LOCALBASE} HDF5_LIB=${LOCALBASE}/lib \
		ZFP_HOME=${STAGEDIR}${LOCALBASE} ZFP_LIB=${LOCALBASE}/lib \
		PREPATH=-Wl,-rpath= SOEXT=so SHFLAG=-shared

CFLAGS+=	-fPIC

PLIST_FILES=	include/H5Zzfp.h \
		include/H5Zzfp_lib.h \
		include/H5Zzfp_plugin.h \
		include/H5Zzfp_props.h \
		lib/libh5zzfp.so \
		plugin/libh5zzfp.so

.include <bsd.port.mk>
