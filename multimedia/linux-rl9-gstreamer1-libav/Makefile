PORTNAME=	gstreamer1-libav
PORTVERSION=	1.18.4
DISTVERSIONSUFFIX=	-1.el9
MASTER_SITES=	RPMFUSION9
#PKGNAMESUFFIX=	-libav
CATEGORIES=	multimedia linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GStreamer1 libav library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://gstreamer.freedesktop.org/

LICENSE=	LGPL20+

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
USE_LINUX=	ffmpeg-libs gstreamer1

CONFLICTS=	linux-c7-${PORTNAME}${PKGNAMESUFFIX}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
