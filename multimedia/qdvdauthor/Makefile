# New ports collection makefile for:   qdvdauthor
# Date created:        05/07/04
# Whom:                oz@nixil.net
#
# $FreeBSD$
#

PORTNAME=	qdvdauthor
PORTVERSION=	0.0.7
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	oz@nixil.net
COMMENT=	QT graphical frontend for dvdauthor

BUILD_DEPENDS=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	Magick.6:${PORTSDIR}/graphics/ImageMagick \
		xine.9:${PORTSDIR}/multimedia/libxine
RUN_DEPENDS=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools

HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_QT_VER=	3
QT_NONSTANDARD=	yes
CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS=	--qt-dir=${X11BASE} --with-image-magick-lib \
		--build-qslideshow --build-wxine
NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qdvdauthor ${PREFIX}/bin/qdvdauthor
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qslideshow ${PREFIX}/bin/qslideshow
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qxine      ${PREFIX}/bin/qxine

.include <bsd.port.mk>
