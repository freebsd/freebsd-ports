# $FreeBSD$

PORTNAME=	svt-av1
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	multimedia
PKGNAMEPREFIX=	gstreamer1-plugins-

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GStreamer (svt-av1) plugin

LICENSE=	LGPL21+ # based on SPDX header
LICENSE_FILE=	${_LICENSE_STORE}/LGPL21

LIB_DEPENDS=	libSvtAv1Enc.so:multimedia/svt-av1

USES=		gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	glib20
USE_GSTREAMER1=	yes
GH_ACCOUNT=	OpenVisualCloud
GH_PROJECT=	SVT-AV1
WRKSRC_SUBDIR=	gstreamer-plugin
PLIST_FILES=	lib/gstreamer-1.0/libgstsvtav1enc.so

post-patch:
	@${REINPLACE_CMD} '/-O2/d' ${WRKSRC}/meson.build

.include <bsd.port.mk>
