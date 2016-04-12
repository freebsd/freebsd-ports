# Created by: roland.jesse@gmx.net
# $FreeBSD$

PORTNAME=	SoXt
PORTVERSION=	1.3.0
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://bitbucket.org/Coin3D/coin/downloads/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GUI binding for using Open Inventor with Xt/Motif

LIB_DEPENDS=	libCoin.so:graphics/Coin

USES=		libtool motif pathfix perl5 shebangfix
USE_GL=		yes
USE_PERL5=	build
SHEBANG_FILES=	cfg/doxy4win.pl
USE_XORG=	xi
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pthread=yes --with-coin=${LOCALBASE}
# avoid renaming of soxt-config and soxt-config.1
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
