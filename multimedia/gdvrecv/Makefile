# New ports collection makefile for:   gdvrecv
# Date created:                        01 Nov 2004
# Whom:                                Henri Michelon <hmichelon at e-cml.org>
#
# $FreeBSD$
#

PORTNAME=	gdvrecv
PORTVERSION=	1.2
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=gdvrecv

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DV Tools for FreeBSD

USE_BZIP2=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
DESKTOP_ENTRIES="Capture Video" \
		"Capture from FireWire Camera" \
		"${PREFIX}/share/pixmaps/gdvrecv/camcorder.png" \
		"gdvrecv" \
		"Application;AudioVideo;" \
		true

CONFLICTS=	dvts-[0-9]*

.include <bsd.port.mk>
