# Created by: Alexander V. Ribchansky <triosoft@triosoft.com.ua>
# $FreeBSD$

PORTNAME=	k9copy
PORTVERSION=	2.3.4
PORTREVISION=	9
CATEGORIES=	multimedia kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-kde4/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	egoliveira@gmail.com
COMMENT=	DVD-9 to DVD-5 shrinking application for KDE

LIB_DEPENDS=	xine:${PORTSDIR}/multimedia/libxine \
		mpeg2:${PORTSDIR}/multimedia/libmpeg2 \
		avcodec:${PORTSDIR}/multimedia/ffmpeg

USES=		cmake gettext
USE_KDE4=	kdeprefix kdelibs automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build

LATEST_LINK=	${PORTNAME}-kde4

OPTIONS_DEFINE=	MENCODER MPLAYER DVDAUTHOR
MENCODER_DESC=	MEncoder support
MPLAYER_DESC=	MPlayer support
DVDAUTHOR_DESC=	DVD Author support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMENCODER}
RUN_DEPENDS+=	mencoder:${PORTSDIR}/multimedia/mencoder
.endif

.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if ${PORT_OPTIONS:MDVDAUTHOR}
RUN_DEPENDS+=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor
.endif

.include <bsd.port.mk>
