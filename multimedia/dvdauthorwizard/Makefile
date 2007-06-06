# New ports collection makefile for:   dvdauthorwizard
# Date created:        30 May 2007
# Whom:                liu_yinghong@yahoo.com.cn
#
# $FreeBSD$
#

PORTNAME=	dvdauthorwizard
PORTVERSION=	1.4.6
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	DVDAuthorWizard-${PORTVERSION}

MAINTAINER=	liu_yinghong@yahoo.com.cn
COMMENT=	The tool for creating a DVD with fully animated menu from MPEG-2 files

NO_BUILD=	yes
USE_BZIP2=	yes
REINPLACE_ARGS=	-i ""

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash \
		convert:${PORTSDIR}/graphics/ImageMagick \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		png2yuv:${PORTSDIR}/multimedia/mjpegtools \
		sox:${PORTSDIR}/audio/sox \
		transcode:${PORTSDIR}/multimedia/transcode \
		kdialog:${PORTSDIR}/x11/kdebase3

do-patch:
	@${REINPLACE_CMD} 's|/bin/bash|/bin/sh|' ${WRKSRC}/inst.sh
	@${REINPLACE_CMD} 's|/bin/bash|/usr/local/bin/bash|' \
		${WRKSRC}/bin/DVDAuthorWizard-Builder.sh

do-install:
	@cd ${WRKSRC} && ${SH} inst.sh ${WRKSRC} ${LOCALBASE}

.include <bsd.port.mk>
