PORTNAME=	SoXt
PORTVERSION=	1.3.0
PORTREVISION=	9
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://bitbucket.org/Coin3D/coin/downloads/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GUI binding for using Open Inventor with Xt/Motif
WWW=		https://bitbucket.org/Coin3D/coin/wiki/Home

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

BROKEN_FreeBSD_14=	error: couldn't compile and link with Motif
BROKEN_FreeBSD_15=	error: couldn't compile and link with Motif

LIB_DEPENDS=	libCoin.so:graphics/Coin

USES=		gl libtool motif pathfix perl5 shebangfix xorg
USE_GL=		gl
USE_PERL5=	build
SHEBANG_FILES=	cfg/doxy4win.pl
USE_XORG=	xi
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pthread=yes --with-coin=${LOCALBASE}
# avoid renaming of soxt-config and soxt-config.1
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
