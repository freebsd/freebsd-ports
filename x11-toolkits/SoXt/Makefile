# New ports collection makefile for:	SoXt
# Date created:				24 April 2003
# Whom:					roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=	SoXt
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.coin3d.org/pub/coin/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI binding for using Open Inventor with Xt/Motif

LIB_DEPENDS=	Coin.44:${PORTSDIR}/graphics/Coin

USE_GL=		yes
USE_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--with-pthread=yes --with-coin=${X11BASE}
# avoid renaming of soxt-config and soxt-config.1
CONFIGURE_TARGET=	--target=""
INSTALLS_SHLIB=	yes
MAN1=		soxt-config.1

.include <bsd.port.mk>
