# Created by: Key-Teck SIN <ktsin@acm.org>
# $FreeBSD$

PORTNAME=	grive
PORTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	ktsin@acm.org
COMMENT=	Open source client for Google Drive

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libgcrypt.so:security/libgcrypt \
		libjson-c.so:devel/json-c \
		libyajl.so:devel/yajl

USE_GITHUB=	yes
GH_ACCOUNT=	Grive
GH_TAGNAME=	27817e8

USES=		cmake
CXXFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/grive man/man1/grive.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/FIND_LIBRARY/s,json,&-c,' \
		${WRKSRC}/cmake/Modules/FindJSONC.cmake
# Do not build Qt4-based frontend: it's buggy and quite useless anyway
	@${REINPLACE_CMD} -e '/ bgrive/d' ${WRKSRC}/CMakeLists.txt
# Allow to build with GCC 4.2
	@${REINPLACE_CMD} -e 's,log::,gr::&,g' ${WRKSRC}/grive/src/main.cc

.include <bsd.port.mk>
