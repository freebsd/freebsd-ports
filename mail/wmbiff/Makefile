# Created by: Jim Mock <jim@FreeBSD.org>

PORTNAME=	wmbiff
PORTVERSION=	0.4.36
PORTREVISION=	1
CATEGORIES=	mail windowmaker afterstep
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	xbiff-like Window Maker dock app

LICENSE=	GPLv2

USES=		pkgconfig xorg

USE_XORG=	x11 xext xpm
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GNUTLS
OPTIONS_DEFAULT=GNUTLS

GNUTLS_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgnutls.so:security/gnutls \
			libgpg-error.so:security/libgpg-error
GNUTLS_CONFIGURE_ON=	--with-libgcrypt-prefix=${LOCALBASE}
GNUTLS_CONFIGURE_OFF=	--disable-crypto

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS *=/ s/scripts//' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/security.debian.rb/ s/^/# /' \
		${WRKSRC}/wmbiff/sample.wmbiffrc

post-install:
	${INSTALL_DATA} ${WRKSRC}/wmbiff/sample.wmbiffrc ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
