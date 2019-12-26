# Created by: Henri Michelon <hmichelon at e-cml.org>
# $FreeBSD$

PORTNAME=	gdvrecv
PORTVERSION=	1.2
PORTREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DV tools for FreeBSD

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gnome python:2.7 tar:bzip2
USE_GNOME=	pygtk2
USE_PYTHON=	distutils
DESKTOP_ENTRIES="Capture Video" \
		"Capture from FireWire Camera" \
		"${PREFIX}/share/pixmaps/gdvrecv/camcorder.png" \
		"gdvrecv" \
		"AudioVideo;Video;" \
		true

CONFLICTS=	dvts-[0-9]*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/firewire.so

.include <bsd.port.mk>
