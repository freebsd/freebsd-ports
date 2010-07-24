# New ports collection makefile for:	libomxil-bellagio
# Date created:		2009-10-04
# Whom:			Thinker K.F. Li <thinker@branda.to>
#
# $FreeBSD$
#

PORTNAME=	libomxil-bellagio
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/omxil/omxil/Bellagio%200.9.1

MAINTAINER=	thinker@branda.to
COMMENT=	Bellagio is an implementation of the OpenMAX IL API

LIB_DEPENDS=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg

BROKEN=		bad plist

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=	omxregister-bellagio.1

.include <bsd.port.mk>
