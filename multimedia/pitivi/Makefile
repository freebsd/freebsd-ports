# New ports collection makefile for:	PiTiVi
# Date created:				20 Dec 2004
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pitivi
PORTVERSION=	0.1.10
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Gstreamer based non-linear audio/video editor

BUILD_DEPENDS=	gnonlin-config:${PORTSDIR}/multimedia/gnonlin \
		${PYTHON_SITELIBDIR}/gst/_gst.so:${PORTSDIR}/multimedia/py-gstreamer
RUN_DEPENDS=	gnonlin-config:${PORTSDIR}/multimedia/gnonlin \
		${PYTHON_SITELIBDIR}/gst/_gst.so:${PORTSDIR}/multimedia/py-gstreamer

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnometarget pygtk2 pkgconfig pygnome2
USE_GSTREAMER=	yes
USE_LIBTOOL_VER=15
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs-build
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Configure fails on !i386"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${LOCALBASE}/bin/python|g' \
		${WRKSRC}/bin/pitivi.in
	@${REINPLACE_CMD} -e 's|0.1.9|0.1.10|g' \
		${WRKSRC}/pitivi/ui/mainwindow.py

.include <bsd.port.post.mk>
