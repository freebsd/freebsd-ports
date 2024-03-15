PORTNAME=	SoXt
DISTVERSION=	1.4.1
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://github.com/coin3d/${PORTNAME:tl}/releases/download/${DISTVERSIONFULL}/
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}-src

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GUI binding for using Open Inventor with Xt/Motif
WWW=		https://github.com/coin3d/soxt

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_14=	error: couldn't compile and link with Motif
BROKEN_FreeBSD_15=	error: couldn't compile and link with Motif

LIB_DEPENDS=	libCoin.so:graphics/Coin

USES=		gl libtool motif pathfix perl5 pkgconfig shebangfix xorg
USE_GL=		gl
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XORG=	ice sm x11 xext xi xmu xt

SHEBANG_FILES=	cfg/doxy4win.pl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS+=	--with-pthread=yes --with-coin=${LOCALBASE}

# avoid renaming of soxt-config and soxt-config.1
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME:tl}
.include <bsd.port.mk>
