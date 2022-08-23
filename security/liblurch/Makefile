PORTNAME=	liblurch
PORTVERSION=	0.2.1
CATEGORIES=	security net-im net
MASTER_SITES=	https://research.ngportal.com/lurch/

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
