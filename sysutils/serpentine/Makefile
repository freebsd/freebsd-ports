# New ports collection makefile for:	serpentine
# Date created:		2005-06-25
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	serpentine
PORTVERSION=	0.6.1
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
USE_GNOME=	pygnomeextras
USE_GMAKE=	yes
USE_GSTREAMER=	core
USE_PYTHON=	2.4+

.include <bsd.port.mk>
