# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmbiff
PORTVERSION=	0.4.27
PORTREVISION=	13
CATEGORIES=	mail windowmaker afterstep
MASTER_SITES=	SF

MAINTAINER=	garga@FreeBSD.org
COMMENT=	An xbiff-like Window Maker dock app

LICENSE=	GPLv2

OPTIONS_DEFINE=	GNUTLS

USE_XORG=	xpm
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/wmbiff \
		lib/wmbiff/security.debian.rb \
		man/man1/wmbiff.1.gz \
		man/man5/wmbiffrc.5.gz \
		%%DATADIR%%/sample.wmbiffrc \
		%%DATADIR%%/skins/wmbiff-master-contrast.xpm \
		%%DATADIR%%/skins/wmbiff-master-led.xpm
PLIST_DIRS=	%%DATADIR%%/skins \
		%%DATADIR%% \
		lib/wmbiff

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt \
		gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-libgnutls-prefix=${LOCALBASE} \
			--with-libgcrypt-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-crypto
.endif

post-install:
	@${ECHO_MSG} "===>   Installing sample.wmbiffrc to ${DATADIR}"
	@${ECHO_MSG} "===>   Modify it to suit your needs and copy to ~/.wmbiffrc"
	${INSTALL_DATA} -m 644 ${WRKSRC}/wmbiff/sample.wmbiffrc ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
