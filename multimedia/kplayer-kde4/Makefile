# New ports collection makefile for:	kplayer
# Date created:				Fri Apr 11 09:12:55 CEST 2003
# Whom:					Stefan Eßer <se@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kplayer
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	se@FreeBSD.org
COMMENT=	Movie player based on mplayer

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
