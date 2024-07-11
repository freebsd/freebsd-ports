PORTNAME=	libnghttp2
PORTVERSION=	1.43.0
DISTVERSIONSUFFIX=	-5.el9_4.3
PORTREVISION=	1
CATEGORIES=	www devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	HTTP/2.0 C Library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://nghttp2.org/ \
		https://github.com/nghttp2/nghttp2

LICENSE=	MIT

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	icu
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}
SRC_DISTFILES=	nghttp2-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
