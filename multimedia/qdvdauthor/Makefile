# New ports collection makefile for:   qdvdauthor
# Date created:        05/07/04
# Whom:                oz@nixil.net
#
# $FreeBSD$
#

PORTNAME=	qdvdauthor
PORTVERSION=	0.0.8
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	oz@nixil.net
COMMENT=	QT graphical frontend for dvdauthor

BUILD_DEPENDS=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	xine.12:${PORTSDIR}/multimedia/libxine
RUN_DEPENDS=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools

PLIST_FILES=	bin/qdvdauthor \
		bin/qslideshow \
		bin/qplayer

HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_QT_VER=	3
QT_NONSTANDARD=	yes
CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS=	--qt-dir=${X11BASE} --with-xine-lib \
		--build-qslideshow --build-qplayer
NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qdvdauthor ${PREFIX}/bin/qdvdauthor
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qslideshow ${PREFIX}/bin/qslideshow
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qplayer    ${PREFIX}/bin/qplayer

.include <bsd.port.mk>
