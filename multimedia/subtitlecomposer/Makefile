# New ports collection makefile for:	subtitlecomposer
# Date created:		2008-01-08
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	subtitlecomposer
PORTVERSION=	0.3
CATEGORIES=	multimedia
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=subcomposer

MAINTAINER=	makc@issp.ac.ru
COMMENT=	Subtitle editor for KDE

LIB_DEPENDS=	tag.5:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gstreamer

WRKSRC=	${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
