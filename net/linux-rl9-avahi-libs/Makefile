PORTNAME=	avahi
PORTVERSION=	0.8
DISTVERSIONSUFFIX=	-20.el9
PORTREVISION=	3
CATEGORIES=	net linux
PKGNAMESUFFIX=	-libs

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for Avahi (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.avahi.org/

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	dbuslibs libevent
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

CONFLICTS=	linux-c6-${PORTNAME}${PKGNAMESUFFIX} linux-c7-${PORTNAME}${PKGNAMESUFFIX}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
