PORTNAME=	libva
PORTVERSION=	2.11.0
DISTVERSIONSUFFIX=	-5.el9
CATEGORIES=	multimedia linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT?=	VAAPI wrapper and dummy driver (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://github.com/intel/libva

LICENSE=	MIT

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libdrm wayland xorglibs
USE_LINUX_RPM=	yes


LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}
SRC_DISTFILES=	${PORTNAME}-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
