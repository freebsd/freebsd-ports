# New ports collection makefile for: dvbcut
# Date created:		Mon Dec 19 23:20:01 CET 2005
# Whom:			se@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	dvbcut
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=dvbcut
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	se@FreeBSD.org
COMMENT=	Qt application for cutting of MPEG PS and MPEG TS streams (DVB)

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons \
		mplayer:${PORTSDIR}/multimedia/mplayer
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer
LIB_DEPENDS=	avutil.1:${PORTSDIR}/multimedia/ffmpeg-devel \
		ao.3:${PORTSDIR}/audio/libao

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
ALL_TARGET=	build
MAKE_ENV=	QTDIR=${QT_PREFIX} FFMPEG=${PREFIX} LDFLAGS="${LDFLAGS}"
CFLAGS+=	-pthread
LDFLAGS+=	-pthread

MAN1=		dvbcut.1
PLIST_FILES=	bin/dvbcut

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/bin/dvbcut ${TARGETDIR}/bin/
		${INSTALL_MAN} ${WRKSRC}/dvbcut.1 ${TARGETDIR}/man/man1/

.include <bsd.port.mk>
