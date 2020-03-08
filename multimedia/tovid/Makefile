# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tovid
PORTVERSION=	0.35.2
DISTVERSIONPREFIX=	tovid-
PORTREVISION=	7
CATEGORIES=	multimedia python

MAINTAINER=	grepper@gmail.com
COMMENT=	Suite of tools for making DVD video disks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	txt2tags:textproc/txt2tags
LIB_DEPENDS=	libTix8.4.3.so:x11-toolkits/tix
RUN_DEPENDS=	mplayer:multimedia/mplayer \
		mplex:multimedia/mjpegtools \
		ffmpeg:multimedia/ffmpeg \
		composite:graphics/ImageMagick6 \
		dvdauthor:multimedia/dvdauthor \
		growisofs:sysutils/dvd+rw-tools \
		sox:audio/sox \
		normalize:audio/normalize \
		lame:audio/lame \
		gnubc>0:math/gnubc \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR} \
		bash:shells/bash

USES=		gnome python:2.7 shebangfix
SHEBANG_FILES= src/set_chapters src/titleset-wizard src/todiscgui src/tovid-stats
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	tovid-suite

PYDISTUTILS_INSTALLNOSINGLE=	yes

INSTALLS_ICONS=	yes
MANDIRS=	${MANPREFIX}/share/man

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS TRANSCODE
TRANSCODE_DESC=	Faster seeks when making menus. Needs mjpegtools enabled.

TRANSCODE_RUN_DEPENDS=	transcode:multimedia/transcode

.include <bsd.port.mk>
