PORTNAME=	matio
PORTVERSION=	1.5.26
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Library for reading and writing Matlab MAT files
WWW=		https://sourceforge.net/projects/matio/

LICENSE=	BSD2CLAUSE

USES=		7z compiler:c11 cpe libtool pathfix

CPE_VENDOR=	matio_project

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
PLIST_SUB=	SHLIB_VER=11.1.1

OPTIONS_DEFINE=	HDF5
OPTIONS_DEFAULT=	HDF5

HDF5_DESC=	Support for MAT file version 7.3
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_CONFIGURE_ON=	--enable-mat73=yes \
			--with-hdf5=${LOCALBASE}

post-extract:
	@${CHMOD} +x ${WRKSRC}/configure

.include <bsd.port.mk>
