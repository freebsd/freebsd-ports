# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tovid
PORTVERSION=	0.35.2
CATEGORIES=	multimedia python
MASTER_SITES=	http://github.com//tovid-suite/tovid/archive/

MAINTAINER=	grepper@gmail.com
COMMENT=	Suite of tools for making DVD video disks

LICENSE=	GPLv2

BUILD_DEPENDS=	txt2tags:${PORTSDIR}/textproc/txt2tags
LIB_DEPENDS=	libTix8.4.3.so:${PORTSDIR}/x11-toolkits/tix
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		mplex:${PORTSDIR}/multimedia/mjpegtools \
		ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		composite:${PORTSDIR}/graphics/ImageMagick \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		sox:${PORTSDIR}/audio/sox \
		normalize:${PORTSDIR}/audio/normalize \
		lame:${PORTSDIR}/audio/lame \
		gnubc>0:${PORTSDIR}/math/gnubc \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter \
		bash:${PORTSDIR}/shells/bash

USES=		python
USE_PYTHON=	autoplist distutils

PYDISTUTILS_INSTALLNOSINGLE=	yes

INSTALLS_ICONS=	yes
MANDIRS=	${MANPREFIX}/share/man

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS TRANSCODE
TRANSCODE_DESC=	Faster seeks when making menus. Needs mjpegtools enabled.

TRANSCODE_RUN_DEPENDS=	transcode:${PORTSDIR}/multimedia/transcode

post-extract:
	${MV} ${WRKDIR}/${PORTNAME}-${PORTNAME}-${PORTVERSION} ${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
