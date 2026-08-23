PORTNAME=	matio
PORTVERSION=	1.6.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/tbeu/matio/releases/download/v${PORTVERSION}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Library for reading and writing Matlab MAT files
WWW=		https://github.com/tbeu/matio/

LICENSE=	BSD2CLAUSE

USES=		compiler:c11 cpe libtool pathfix

CPE_VENDOR=	matio_project

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
PLIST_SUB=	SHLIB_VER=14.1.0

OPTIONS_DEFINE=	HDF5
OPTIONS_DEFAULT=	HDF5

HDF5_DESC=	Support for MAT file version 7.3
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_CONFIGURE_ON=	--enable-mat73=yes \
			--with-hdf5=${LOCALBASE}

post-extract:
	@${CHMOD} +x ${WRKSRC}/configure

.include <bsd.port.mk>
