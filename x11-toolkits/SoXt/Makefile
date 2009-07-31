# New ports collection makefile for:	SoXt
# Date created:				24 April 2003
# Whom:					roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=	SoXt
PORTVERSION=	1.2.2
PORTREVISION=	5
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.coin3d.org/pub/coin/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI binding for using Open Inventor with Xt/Motif

LIB_DEPENDS=	Coin.60:${PORTSDIR}/graphics/Coin

USE_GL=		yes
USE_MOTIF=	yes
USE_PERL5_BUILD=	yes
USE_XORG=	xi
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--with-pthread=yes --with-coin=${LOCALBASE}
# avoid renaming of soxt-config and soxt-config.1
USE_LDCONFIG=	yes
MAN1=		soxt-config.1

post-patch:
	${REINPLACE_CMD} -e "s,echo aout, echo elf," ${WRKSRC}/configure

.include <bsd.port.mk>
