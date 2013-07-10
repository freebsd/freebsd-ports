# Created by: roland.jesse@gmx.net
# $FreeBSD$

PORTNAME=	SoXt
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ftp.coin3d.org/coin/src/all/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	GUI binding for using Open Inventor with Xt/Motif

LIB_DEPENDS=	Coin.61:${PORTSDIR}/graphics/Coin

USES=		motif pathfix
USE_GL=		yes
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
