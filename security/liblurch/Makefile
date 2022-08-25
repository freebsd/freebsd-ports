PORTNAME=	liblurch
PORTVERSION=	0.7.0
CATEGORIES=	security net-im net
MASTER_SITES=	https://github.com/gkdr/lurch/releases/download/v0.7.0/ 

DISTNAME=       lurch-${PORTVERSION}-src
MAINTAINER=	micadeyeye@gmail.com
COMMENT=	Portable OMEMO Encryption Library

LICENSE=	GPLv2 # only

LIB_DEPENDS=	libmxml.so:textproc/mxml \
		libpurple.so:net-im/libpurple

GNU_CONFIGURE=	yes
USES=		gmake cpe libtool pathfix pkgconfig
USE_LDCONFIG=	yes
CPE_VENDOR=	micadeyeye

.include <bsd.port.mk>
