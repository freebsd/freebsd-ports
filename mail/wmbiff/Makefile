# Created by: Jim Mock <jim@FreeBSD.org>

PORTNAME=	wmbiff
PORTVERSION=	0.4.36
CATEGORIES=	mail windowmaker afterstep
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	xbiff-like Window Maker dock app

LICENSE=	GPLv2

USES=		shebangfix xorg

USE_XORG=	x11 xext xpm
SHEBANG_FILES=	scripts/security.debian.rb
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GNUTLS
OPTIONS_DEFAULT=GNUTLS

GNUTLS_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgnutls.so:security/gnutls \
			libgpg-error.so:security/libgpg-error
GNUTLS_CONFIGURE_ON=	--with-libgnutls-prefix=${LOCALBASE} \
			--with-libgcrypt-prefix=${LOCALBASE}
GNUTLS_CONFIGURE_OFF=	--disable-crypto

post-install:
	${INSTALL_DATA} ${WRKSRC}/wmbiff/sample.wmbiffrc ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
