# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tovid
PORTVERSION=	0.35.2
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	https://github.com//tovid-suite/tovid/archive/

MAINTAINER=	grepper@gmail.com
COMMENT=	Suite of tools for making DVD video disks

LICENSE=	GPLv2

BUILD_DEPENDS=	txt2tags:textproc/txt2tags
LIB_DEPENDS=	libTix8.4.3.so:x11-toolkits/tix
RUN_DEPENDS=	mplayer:multimedia/mplayer \
		mplex:multimedia/mjpegtools \
		ffmpeg:multimedia/ffmpeg \
		composite:graphics/ImageMagick \
		dvdauthor:multimedia/dvdauthor \
		growisofs:sysutils/dvd+rw-tools \
		sox:audio/sox \
		normalize:audio/normalize \
		lame:audio/lame \
		gnubc>0:math/gnubc \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter \
		bash:shells/bash

USES=		python
USE_PYTHON=	autoplist distutils

PYDISTUTILS_INSTALLNOSINGLE=	yes

INSTALLS_ICONS=	yes
MANDIRS=	${MANPREFIX}/share/man

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS TRANSCODE
TRANSCODE_DESC=	Faster seeks when making menus. Needs mjpegtools enabled.

TRANSCODE_RUN_DEPENDS=	transcode:multimedia/transcode

post-extract:
	${MV} ${WRKDIR}/${PORTNAME}-${PORTNAME}-${PORTVERSION} ${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
