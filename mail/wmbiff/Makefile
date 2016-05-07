# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmbiff
PORTVERSION=	0.4.27
PORTREVISION=	18
CATEGORIES=	mail windowmaker afterstep
MASTER_SITES=	SF

MAINTAINER=	garga@FreeBSD.org
COMMENT=	xbiff-like Window Maker dock app

LICENSE=	GPLv2

OPTIONS_DEFINE=	GNUTLS

USES=		shebangfix
SHEBANG_FILES=	scripts/security.debian.rb
USE_XORG=	xpm
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/wmbiff \
		lib/wmbiff/security.debian.rb \
		man/man1/wmbiff.1.gz \
		man/man5/wmbiffrc.5.gz \
		%%DATADIR%%/sample.wmbiffrc \
		%%DATADIR%%/skins/wmbiff-master-contrast.xpm \
		%%DATADIR%%/skins/wmbiff-master-led.xpm

GNUTLS_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ON=	--with-libgnutls-prefix=${LOCALBASE} \
			--with-libgcrypt-prefix=${LOCALBASE}
GNUTLS_CONFIGURE_OFF=	--disable-crypto

post-install:
	@${ECHO_MSG} "===>   Installing sample.wmbiffrc to ${DATADIR}"
	@${ECHO_MSG} "===>   Modify it to suit your needs and copy to ~/.wmbiffrc"
	${INSTALL_DATA} ${WRKSRC}/wmbiff/sample.wmbiffrc ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
