# New ports collection makefile for:	KMplayer
# Date created:				Jan 31, 2003
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kmplayer
PORTVERSION=	0.6.5a
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.xs4all.nl/%7Ejjvrieze/

MAINTAINER=	will@FreeBSD.org
COMMENT=	KDE frontend to mplayer

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/kmplayer
USE_KDEBASE_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--with-x=${X11BASE} --disable-debug

.include <bsd.port.mk>
