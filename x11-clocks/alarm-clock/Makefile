# New ports collection makefile for:	alarm-clock
# Date created:		2008-06-16
# Whom:			Romain Tartière <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	alarm-clock
PORTVERSION=	0.9.11.2
PORTREVISION=	1
CATEGORIES=	x11-clocks deskutils
MASTER_SITES=	http://dp0154.debowypark.waw.pl/ac/downloads/

MAINTAINER=	romain@blogreen.org
COMMENT=	Alarm Clock for the GNOME desktop

LIB_DEPENDS=	rsvg-2:${PORTSDIR}/graphics/librsvg2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify \
		${PYTHON_SITELIBDIR}/gst-0.10/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	${PORTVERSION:R}

.include <bsd.port.mk>
