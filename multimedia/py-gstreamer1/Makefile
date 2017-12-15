# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	gstreamer
PORTVERSION=	1.12.3
CATEGORIES=	multimedia python
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	1
DISTNAME=	gst-python-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer python bindings

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

USES=		gmake libtool localbase pathfix pkgconfig python tar:xz
.if ${FLAVOR:Upy27:Mpy2*}
USE_GNOME=	pygobject3
.else
USE_GNOME=	py3gobject3
.endif
py34_PLIST=	${.CURDIR}/pkg-plist-py3
py35_PLIST=	${.CURDIR}/pkg-plist-py3
py36_PLIST=	${.CURDIR}/pkg-plist-py3
USE_PYTHON=	flavors
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
PLIST_SUB=	VERSION="${GST_VERSION}"
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
