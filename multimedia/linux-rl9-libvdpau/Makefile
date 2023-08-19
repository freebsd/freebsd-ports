PORTNAME=	libvdpau
PORTVERSION=	1.5
DISTVERSIONSUFFIX=	-1.el9
CATEGORIES=	multimedia linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	VDPAU wrapper and tracing library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://freedesktop.org/wiki/Software/VDPAU

LICENSE=	MIT

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libdrm wayland xorglibs
USE_LINUX_RPM=	yes


LIB_DISTNAMES=	${PORTNAME}-${DISTVERSIONFULL} \
		${PORTNAME}-trace-${DISTVERSIONFULL}
SRC_DISTFILES=	${PORTNAME}-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
