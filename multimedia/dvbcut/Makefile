# New ports collection makefile for: dvbcut
# Date created:		Mon Dec 19 23:20:01 CET 2005
# Whom:			se@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	dvbcut
PORTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mr511.de/dvbcut/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt application for cutting of MPEG PS and MPEG TS streams (DVB)

BUILD_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer
LIB_DEPENDS=	a52.0:${PORTSDIR}/audio/liba52 \
		ao.4:${PORTSDIR}/audio/libao \
		mad.2:${PORTSDIR}/audio/libmad \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ffmpeg=${LOCALBASE}
MAKEFILE=	makefile

MAN1=		dvbcut.1
PLIST_FILES=	bin/dvbcut

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dvbcut ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dvbcut.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
