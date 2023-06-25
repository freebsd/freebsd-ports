PORTNAME=	gstreamer1
PORTVERSION=	1.18.4
DISTVERSIONSUFFIX=	-4.el9
CATEGORIES=	multimedia linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GStreamer1 library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://gstreamer.freedesktop.org/

LICENSE=	LGPL20+

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
#USE_LINUX=	

LIB_DISTNAMES=	${PORTNAME}-${DISTVERSIONFULL} \
		${PORTNAME}-plugins-base-${DISTVERSION}-5.el9.0.1 \
		${PORTNAME}-plugins-bad-free-${DISTVERSION}-6.el9 \
		${PORTNAME}-plugins-good-${DISTVERSION}-6.el9 \
		${PORTNAME}-plugins-ugly-free-${DISTVERSION}-3.el9

SRC_DISTFILES=	gstreamer1-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
