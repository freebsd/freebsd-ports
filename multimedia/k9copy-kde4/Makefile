# New ports collection makefile for:	k9copy
# Date created:				19 Dec 2005
# Whom:			Alexander V. Ribchansky <triosoft@triosoft.com.ua>
#
# $FreeBSD$

PORTNAME=	k9copy
PORTVERSION=	2.3.4
PORTREVISION=	4
CATEGORIES=	multimedia kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-kde4/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	egoliveira@gmail.com
COMMENT=	A DVD-9 to DVD-5 shrinking application for KDE

LIB_DEPENDS=	xine:${PORTSDIR}/multimedia/libxine \
		mpeg2:${PORTSDIR}/multimedia/libmpeg2 \
		avcodec:${PORTSDIR}/multimedia/ffmpeg

USE_CMAKE=	yes
USE_KDE4=	kdeprefix kdelibs automoc4
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

LATEST_LINK=	${PORTNAME}-kde4

OPTIONS=	MENCODER	"Install MEncoder (requires MPlayer)"	Off \
		MPLAYER		"Install MPlayer"			Off \
		DVDAUTHOR	"Install DVD Author"			Off

.include <bsd.port.options.mk>

.if defined(WITH_MENCODER)
RUN_DEPENDS+=	mencoder:${PORTSDIR}/multimedia/mencoder
.endif

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if defined(WITH_DVDAUTHOR)
RUN_DEPENDS+=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor
.endif

.include <bsd.port.mk>
