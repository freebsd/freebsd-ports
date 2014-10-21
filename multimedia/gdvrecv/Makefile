# Created by: Henri Michelon <hmichelon at e-cml.org>
# $FreeBSD$

PORTNAME=	gdvrecv
PORTVERSION=	1.2
PORTREVISION=	9
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DV tools for FreeBSD

USES=		python tar:bzip2
USE_GNOME=	pygtk2
USE_PYTHON=	distutils
DESKTOP_ENTRIES="Capture Video" \
		"Capture from FireWire Camera" \
		"${PREFIX}/share/pixmaps/gdvrecv/camcorder.png" \
		"gdvrecv" \
		"AudioVideo;Video;" \
		true

CONFLICTS=	dvts-[0-9]*

.include <bsd.port.mk>
