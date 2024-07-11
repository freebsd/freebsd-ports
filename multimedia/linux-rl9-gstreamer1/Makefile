PORTNAME=	gstreamer1
PORTVERSION=	1.22.1
DISTVERSIONSUFFIX=	-2.el9
PORTREVISION=	1
CATEGORIES=	multimedia linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GStreamer1 library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://gstreamer.freedesktop.org/

LICENSE=	LGPL20+

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libnghttp2 orc vulkan
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${PORTNAME}-${DISTVERSIONFULL} \
		${PORTNAME}-plugins-base-${DISTVERSION}-2.el9 \
		${PORTNAME}-plugins-bad-free-${DISTVERSION}-4.el9 \
		${PORTNAME}-plugins-good-${DISTVERSION}-2.el9 \
		${PORTNAME}-plugins-ugly-free-${DISTVERSION}-1.el9

SRC_DISTFILES=	gstreamer1-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes


.include <bsd.port.mk>
