PORTNAME=	liblurch
PORTVERSION=	0.2.1
PORTREVISION=	4
CATEGORIES=	security net-im net
MASTER_SITES=	https://research.ngportal.com/lurch/
PKGNAMESUFFIX=	3
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	micadeyeye@gmail.com
COMMENT=	Portable OMEMO Encryption Library

LICENSE=	GPLv2 # only

LIB_DEPENDS=	libmxml.so:textproc/mxml \
		libpurple.so:net-im/libpurple

CONFLICTS=	

GNU_CONFIGURE=	yes
USES=		gmake cpe libtool pathfix pkgconfig
USE_LDCONFIG=	yes
CPE_VENDOR=	micadeyeye

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

.include <bsd.port.mk>
