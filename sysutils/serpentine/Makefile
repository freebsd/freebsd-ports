# New ports collection makefile for:	serpentine
# Date created:		2005-06-25
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	serpentine
PORTVERSION=	0.6.4
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/${PORTNAME}/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Gnome Audio Cd Buner

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer \
		xmlproc_parse:${PORTSDIR}/textproc/py-xml
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer \
		xmlproc_parse:${PORTSDIR}/textproc/py-xml

USE_X_PREFIX=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pygnomeextras intlhack
USE_GMAKE=	yes
USE_GSTREAMER=	core gnomevfs
USE_PYTHON=	2.4+

OPTIONS=	MUINE "Cd-Burner Plugin for muine audio player (i386 only)" Off

.include <bsd.port.pre.mk>

.if (defined(WITH_MUINE) || exists(${X11BASE}/bin/muine)) && ${ARCH}=="i386"
BUILD_DEPENDS+=	muine:${PORTSDIR}/audio/muine
RUN_DEPENDS+=	muine:${PORTSDIR}/audio/muine
PLIST_SUB+=	MUINE=""
CONFIGURE_ARGS+=	--enable-muine
.else
PLIST_SUB+=	MUINE="@comment "
.endif

.include <bsd.port.post.mk>
